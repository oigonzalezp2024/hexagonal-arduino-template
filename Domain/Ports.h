#ifndef PORTS_H
#define PORTS_H

#include "User.h"

class User; 

class IUserRepository {
public:
    virtual ~IUserRepository() = default;
    virtual User findById(int searchId) const = 0;
    virtual int getMaxUsers() const = 0;
};

class IController {
public:
    virtual ~IController() = default;
    virtual void begin(int cols, int rows) = 0;
    virtual void update() = 0;
};

class ILCDOutput {
public:
    virtual ~ILCDOutput() = default;
    virtual void init(int cols, int rows) = 0;
    virtual void displayUser(const User& user) = 0;
    virtual void displayMessage(const char* message) = 0;
};

class IUserCycleService {
public:
    virtual ~IUserCycleService() = default;
    virtual User getNextUser() = 0;
};

class ITimer {
public:
    virtual ~ITimer() = default;
    virtual unsigned long getTimeMs() const = 0; 
};

#endif // PORTS_H
