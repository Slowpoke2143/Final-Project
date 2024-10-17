#pragma once
#include<iostream>
class User {
protected:
    std::string _login;
    std::string _password;
    std::string _name;
    int _num = 0;

public:
    User() {}
    User(int num, const std::string& login, const std::string& password, const std::string& name) : _num(num), _login(login), _password(password), _name(name){}
    ~User() = default;
      std::string get_login() const { return _login; }
      std::string get_password() const { return _password; }
      std::string get_name() const { return _name; }
      int get_num() const { return _num; }

    bool operator==(User user)
    {
        if (_login == user.get_login() && _password == user.get_password())
        {
            return true;
        }
        return false;
    }
};