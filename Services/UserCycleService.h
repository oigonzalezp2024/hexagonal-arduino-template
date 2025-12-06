// UserCycleService.h
#ifndef USER_CYCLE_SERVICE_H
#define USER_CYCLE_SERVICE_H

#include "../Domain/Ports.h"

// ====================================
//    CAPA DE SERVICIOS DE APLICACIÓN ✨
// ====================================

class UserCycleService : public IUserCycleService {
private:
    IUserRepository* userRepo;
    int currentId = 0;
    const int maxUsers;
public:
    UserCycleService(IUserRepository* repo);
    User getNextUser() override;
};

#endif // USER_CYCLE_SERVICE_H
