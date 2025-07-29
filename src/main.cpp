// main.cpp
#include "LoginSystem.h"
#include <iostream>
#include <string>
#include <fmt/core.h>

int main() {
    LoginSystem system;
    int choice;
    std::string username, password;

    fmt::print("=== 用户登录系统 ===\n");

    while (true) {
        fmt::print( "\n1. 注册\n2. 登录\n3. 登出\n4. 查看当前用户\n5. 退出\n");
        fmt::print( "请选择操作: ");
        std::cin >> choice;

        switch (choice) {
            case 1:
                fmt::print( "输入用户名: ");
                std::cin >> username;
                fmt::print( "输入密码: ");
                std::cin >> password;
                system.registerUser(username, password);
                break;

            case 2:
                if (system.isLogged()) {
                    fmt::print( "已有用户登录，请先登出。\n");
                    break;
                }
                fmt::print( "输入用户名: ");
                std::cin >> username;
                fmt::print( "输入密码: ");
                std::cin >> password;
                system.loginUser(username, password);
                break;

            case 3:
                system.logoutUser();
                break;

            case 4:
                if (system.isLogged()) {
                    fmt::print( "当前登录用户: %s,\n",system.getCurrentUser());
                } else {
                    fmt::print( "当前无用户登录。\n");
                }
                break;

            case 5:
                fmt::print( "再见！\n");
                return 0;

            default:
                fmt::print( "无效选择，请重试。\n");
        }
    }

    return 0;
}