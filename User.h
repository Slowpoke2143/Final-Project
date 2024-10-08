#pragma once
#include<iostream>
class User {
public:
    std::string login;
    std::string password;
    std::string name;

    User() = default;

    User(const std::string& login, const std::string& password, const std::string& name) : login(login), password(password), name(name) {}
};