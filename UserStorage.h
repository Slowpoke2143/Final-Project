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

    bool registerUser(const std::string& login, const std::string& password, const std::string& name);

    int get_length();
    User* get_user(const std::string& login);
    User* get_user(const std::string&& login);

    User* operator[](int& i);
    User* operator[](int i);
};