#pragma once
#include "User.h"
#include<iostream>
class UserStorage {  //HZ 
private:
    User* users;
    int numUsers;

public:
    UserStorage();

    ~UserStorage();

    void registerUser(const std::string& login, const std::string& password, const std::string& name);

    int login(const std::string& login, const std::string& password);
};