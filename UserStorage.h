 #pragma once
#include "User.h"
#include <string>
#include<vector>
#include<iostream>
class UserStorage: public User {
private:
    std::vector<User*> users;

public:
    UserStorage();
    ~UserStorage();

    bool registerUser(int num, const std::string& login, const std::string& password, const std::string& name);

    int get_number(const std::string& login, const std::string& password);
    int get_number(const std::string&& login, const std::string&& password);

    const User* operator[](int& i);
    const User* operator[](int&& i);
};