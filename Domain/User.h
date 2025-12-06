// User.h
#ifndef USER_H
#define USER_H

#include <stddef.h> // Para const char*

// ====================================
//          CAPA DE DOMINIO 🧠
// ====================================

class User {
private:
    const int userId;
    const char* const name;
    
public:
    User(int userId, const char* name)
        : userId(userId), name(name) {} 

    int getUserId() const { return userId; }
    const char* getName() const { return name; }
};

#endif // USER_H
