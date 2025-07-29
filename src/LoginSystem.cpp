#include "LoginSystem.h"
#include <iostream>

bool LoginSystem::registerUser(const std::string& username, const std::string& password) {
    if (username.empty() || password.empty()) {
        std::cout << "用户名或密码不能为空！\n";
        return false;
    }

    if (userExists(username)) {
        std::cout << "用户名已存在！\n";
        return false;
    }

    users[username] = User(username, password);
    std::cout << "注册成功！\n";
    return true;
}

bool LoginSystem::loginUser(const std::string& username, const std::string& password) {
    if (!userExists(username)) {
        std::cout << "用户不存在！\n";
        return false;
    }

    User user = users[username];
    if (user.getPassword() == password) {
        currentUser = username;
        std::cout << "登录成功！欢迎，" << username << "！\n";
        return true;
    } else {
        std::cout << "密码错误！\n";
        return false;
    }
}

void LoginSystem::logoutUser() {
    if (!currentUser.empty()) {
        std::cout << "用户 " << currentUser << " 已登出。\n";
        currentUser.clear();
    } else {
        std::cout << "当前无用户登录。\n";
    }
}

bool LoginSystem::isLogged() const {
    return !currentUser.empty();
}

std::string LoginSystem::getCurrentUser() const {
    return currentUser;
}

bool LoginSystem::userExists(const std::string& username) const {
    return users.find(username) != users.end();
}