// User.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password; // 注意：实际项目中应加密存储

public:
    User();
    User(std::string   username, std::string  password);

    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getPassword() const;

    void setPassword(const std::string& password);
};

#endif // USER_H