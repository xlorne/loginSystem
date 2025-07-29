// main.cpp
#include "LoginSystem.h"
#include <iostream>
#include <string>

int main() {
    LoginSystem system;
    int choice;
    std::string username, password;

    std::cout << "=== 用户登录系统 ===\n";

    while (true) {
        std::cout << "\n1. 注册\n2. 登录\n3. 登出\n4. 查看当前用户\n5. 退出\n";
        std::cout << "请选择操作: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "输入用户名: ";
                std::cin >> username;
                std::cout << "输入密码: ";
                std::cin >> password;
                system.registerUser(username, password);
                break;

            case 2:
                if (system.isLogged()) {
                    std::cout << "已有用户登录，请先登出。\n";
                    break;
                }
                std::cout << "输入用户名: ";
                std::cin >> username;
                std::cout << "输入密码: ";
                std::cin >> password;
                system.loginUser(username, password);
                break;

            case 3:
                system.logoutUser();
                break;

            case 4:
                if (system.isLogged()) {
                    std::cout << "当前登录用户: " << system.getCurrentUser() << "\n";
                } else {
                    std::cout << "当前无用户登录。\n";
                }
                break;

            case 5:
                std::cout << "再见！\n";
                return 0;

            default:
                std::cout << "无效选择，请重试。\n";
        }
    }

    return 0;
}