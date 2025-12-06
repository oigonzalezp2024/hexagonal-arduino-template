#ifndef MOCKS_H
#define MOCKS_H

#include "../Domain/Ports.h"
#include <string>
#include <stddef.h> 

class MockUserRepository : public IUserRepository {
public:
    mutable int findByIdCallCount = 0;
    mutable int lastSearchId = 0;
    
    User findById(int searchId) const override {
        findByIdCallCount++; 
        lastSearchId = searchId;
        return User(searchId, "Mock User");
    }
    int getMaxUsers() const override { return 3; }
};

class MockLCDOutput : public ILCDOutput {
public:
    std::string lastDisplayedMessage = "";
    bool initCalled = false;
    std::string lastDisplayedUserName = ""; 

    void init(int cols, int rows) override { initCalled = true; }
    
    void displayMessage(const char* message) override { lastDisplayedMessage = message; }

    void displayUser(const User& user) override { 
        lastDisplayedUserName = user.getName();
    }
};

class MockUserCycleService : public IUserCycleService {
public:
    mutable int getNextUserCallCount = 0;

    User getNextUser() override {
        getNextUserCallCount++; 
        return User(99, "MOCK CYCLE USER");
    }
};

class MockTimer : public ITimer {
public:
    unsigned long timeValue = 0;
    
    void setTime(unsigned long newTime) {
        timeValue = newTime;
    }
    
    unsigned long getTimeMs() const override {
        return timeValue;
    }
};

#endif // MOCKS_H
