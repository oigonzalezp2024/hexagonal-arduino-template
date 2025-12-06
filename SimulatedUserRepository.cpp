#include "Infrastructure/SimulatedUserRepository.h"

User SimulatedUserRepository::users[SimulatedUserRepository::MAX_USERS] = {
    User(1, "OSCAR GONZALEZ"),
    User(2, "MARIA LOPEZ"),
    User(3, "PEDRO PEREZ")
};

User SimulatedUserRepository::findById(int searchId) const {
    for (int i = 0; i < MAX_USERS; ++i) {
        if (users[i].getUserId() == searchId) {
            return users[i];
        }
    }
    return User(0, "Not Found"); 
}

int SimulatedUserRepository::getMaxUsers() const {
    return MAX_USERS;
}
