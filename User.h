#pragma once
#include<iostream>
#include<string>
#include<vector>
class User {
protected:
    std::string _login;
    std::string _password;
    std::string _name;
    short _uniqValue = 0; // уникальный номер юзера 
public:
    User() {}
    User(const std::string& login, const std::string& password, const std::string& name, short uniqValue) :_login(login), _password(password), _name(name), _uniqValue(uniqValue) {}
    ~User() = default;
    const std::string get_login() const { return _login; }
    const std::string get_password() const { return _password; }
    const  std::string get_name() const { return _name; }
    const int get_uniq_value() const { return _uniqValue; }

    void set_login(std::string login) { _login = login; }
    void set_password(std::string password) { _password = password; }
    void set_name(std::string name) { _name = name; }
    void set_uniq_value(int uniqValue) { _uniqValue = uniqValue; }


    //bool operator==(std::string login)
    //{
    //    if (_login == login)
    //    {
    //        return true;
    //    }
    //    return false;
    //}
};