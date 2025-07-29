// LoginSystem.h
#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include <map>
#include <string>
#include "User.h"

class LoginSystem {
private:
    std::map<std::string, User> users;  // 用户名 -> User 对象
    std::string currentUser;            // 当前登录用户

public:
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void logoutUser();
    [[nodiscard]] bool isLogged() const;
    [[nodiscard]] std::string getCurrentUser() const;

    [[nodiscard]] bool userExists(const std::string& username) const;
};

#endif // LOGINSYSTEM_H