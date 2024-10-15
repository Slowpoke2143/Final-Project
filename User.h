#pragma once
#include<iostream>
class User {
private:
    std::string login;
    std::string password;
    std::string name;

public:

    User(const std::string& login, const std::string& password, const std::string& name) : login(login), password(password), name(name) {}

    const std::string get_login() const { return login; }
    const std::string get_password() const { return password; }
    const std::string get_name() const { return name; }

    bool operator==(User user)
    {
        if (login == user.get_login() && password == user.get_password())
        {
            return true;
        }
        return false;
    }
};