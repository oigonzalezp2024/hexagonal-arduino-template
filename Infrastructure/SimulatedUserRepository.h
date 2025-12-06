#ifndef SIMULATED_USER_REPOSITORY_H
#define SIMULATED_USER_REPOSITORY_H

#include "../Domain/Ports.h"

class SimulatedUserRepository : public IUserRepository {
private:
    static constexpr int MAX_USERS = 3;
    static User users[MAX_USERS]; 
    
public:
    User findById(int searchId) const override;
    int getMaxUsers() const override;
};

#endif // SIMULATED_USER_REPOSITORY_H
