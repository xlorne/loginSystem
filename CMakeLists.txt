cmake_minimum_required(VERSION 3.14)
project(LoginSystem VERSION 1.0 LANGUAGES CXX)

find_package(fmt REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行目标
add_executable(login_system
        src/User.cpp
        src/LoginSystem.cpp
        src/main.cpp
)

# 指定头文件搜索路径（仅对这个 target 生效）
include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(login_system PRIVATE fmt::fmt)