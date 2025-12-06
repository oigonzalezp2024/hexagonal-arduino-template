// TestUserCycleService.cpp
#include "Mocks.h"
#include "../Services/UserCycleService.h"
#include <iostream>
#include <cassert>

void test_UserCycleService_CycleLogic() {
    // 1. Arrange
    MockUserRepository mockRepo;
    UserCycleService serviceUnderTest(&mockRepo); 
    
    // 2. Act & 3. Assert (Cycle 1)
    serviceUnderTest.getNextUser(); 
    assert(mockRepo.lastSearchId == 1 && "Error: Cycle does not start at 1");
    
    // 2. Act & 3. Assert (Cycle 2)
    serviceUnderTest.getNextUser(); 
    assert(mockRepo.lastSearchId == 2 && "Error: Cycle does not advance to 2");

    // 2. Act & 3. Assert (Cycle 3)
    serviceUnderTest.getNextUser(); 
    assert(mockRepo.lastSearchId == 3 && "Error: Cycle does not advance to 3");
    
    // 2. Act & 3. Assert (Cycle 4 - Must return to 1)
    serviceUnderTest.getNextUser(); 
    assert(mockRepo.lastSearchId == 1 && "Error: Cycle does not return to 1 (max=3)");
    
    std::cout << "✅ TestUserCycleService PASSED" << std::endl;
}

// Main test function
void RunAllServiceTests() {
    std::cout << "\n--- Executing Service Tests ---" << std::endl;
    test_UserCycleService_CycleLogic();
}
