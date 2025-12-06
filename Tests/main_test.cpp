// main_test.cpp
#include <iostream>

// Test function declarations
void RunAllServiceTests();
void RunAllControllerTests();

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << " UNIT TESTS - HEXAGONAL ARCHITECTURE" << std::endl;
    std::cout << "===========================================" << std::endl;

    RunAllServiceTests();
    RunAllControllerTests();

    std::cout << "\n===========================================" << std::endl;
    std::cout << "🎉 Core Logic Tests Finished! 🎉" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    return 0;
}