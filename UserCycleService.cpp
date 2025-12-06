// UserCycleService.cpp
#include "Services/UserCycleService.h"

UserCycleService::UserCycleService(IUserRepository* repo)
    : userRepo(repo), maxUsers(repo->getMaxUsers()) {} 

User UserCycleService::getNextUser() {
    currentId = (currentId % maxUsers) + 1;
    return userRepo->findById(currentId);
}
