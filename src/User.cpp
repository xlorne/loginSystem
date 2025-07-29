#include <iostream>
#include <utility>
#include "User.h"

User::User() = default;

User::User(std::string  username, std::string  password)
    : username(std::move(username)), password(std::move(password)) {
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &pwd) {
    password = pwd;
}
