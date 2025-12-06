// TestController.cpp
#include "Mocks.h"
#include "../Application/Controller.h" 
#include <iostream>
#include <cassert>

// --------------------------------------------------
// NOTE: Local simulation of millis() and current_time_ms 
// has been removed. We now use MockTimer.
// --------------------------------------------------

void test_Controller_TimingAndFlow() {
    // 1. Arrange
    MockLCDOutput mockLcd;
    MockUserCycleService mockService;
    MockTimer mockTimer; // <<< NEW: Instantiate the Mock Timer
    
    // The Controller now requires THREE dependencies: 
    // LCD, Service, and Timer (Platform Abstraction)
    Controller controllerUnderTest(&mockLcd, &mockService, &mockTimer); 
    
    // Reset call and time counters
    mockTimer.setTime(0); // Set the initial Mock time
    mockService.getNextUserCallCount = 0;
    
    // Initialization Test (begin)
    controllerUnderTest.begin(16, 2);
    assert(mockLcd.initCalled == true && "Error: init() not called");
    assert(mockLcd.lastDisplayedMessage == "System Ready!" && "Error: Incorrect message displayed");
    
    // 2. Act & 3. Assert (Update before time: 500ms)
    mockTimer.setTime(500); 
    controllerUnderTest.update();
    assert(mockService.getNextUserCallCount == 0 && "Error: Called before 1000ms");
    
    // 2. Act & 3. Assert (Update exactly on time: 1000ms)
    mockTimer.setTime(1000); 
    controllerUnderTest.update();
    assert(mockService.getNextUserCallCount == 1 && "Error: Service not called");
    assert(mockLcd.lastDisplayedUserName == "MOCK CYCLE USER" && "Error: User not displayed");
    
    // 2. Act & 3. Assert (Update right after, not enough time: 1500ms)
    mockTimer.setTime(1500);
    controllerUnderTest.update();
    assert(mockService.getNextUserCallCount == 1 && "Error: Called twice too fast");
    
    // 2. Act & 3. Assert (Update at the next interval: 2000ms)
    mockTimer.setTime(2000);
    controllerUnderTest.update();
    assert(mockService.getNextUserCallCount == 2 && "Error: Not called in the second interval");

    // 2. Act & 3. Assert (Update at the next interval, with a jump: 4000ms)
    mockTimer.setTime(4000); // 2 second jump. Should call 2 more times (2000->3000 and 3000->4000)
    controllerUnderTest.update();
    assert(mockService.getNextUserCallCount == 4 && "Error: Did not call multiple times on jump");
    
    std::cout << "✅ TestController PASSED" << std::endl;
}

// Main test function
void RunAllControllerTests() {
    std::cout << "\n--- Executing Controller Tests ---" << std::endl;
    test_Controller_TimingAndFlow();
}
