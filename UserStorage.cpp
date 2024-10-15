#include "UserStorage.h"
#include<vector>

UserStorage::UserStorage() {}

UserStorage::~UserStorage() 
{
    for (int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
}

bool UserStorage::registerUser(const std::string& login, const std::string& password, const std::string& name) // создает пользователя // если может то true если нет то false
{
    users.push_back(new User(login, password, name));

    for (int i = 0; i < users.size()-1; i++)
    {
        if (users[i] == users[users.size() - 1])
        {
            users.pop_back();
            return false;
        }
    }

    return true;
}

int UserStorage::get_number(const std::string& login, const std::string& password)
{
    for (int i = 0; i < users.size(); i++) 
    {
        if (users[i]->get_login() == login && users[i]->get_password() == password)
        {
            return i; // если успешно то возвращает номер user'а из массива
        }
    }
    return -1; // возвращает при ошибке
}

int UserStorage::get_number(const std::string&& login, const std::string&& password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_login() == login && users[i]->get_password() == password)
        {
            return i; // если успешно то возвращает номер user'а из массива
        }
    }
    return -1; // возвращает при ошибке
}

const User* UserStorage::operator[](int& i) // возвращает ссылку, но есл нет доступа то nullptr
{
    if (i < users.size())
        return users[i];
    return nullptr;
}
const User* UserStorage::operator[](int&& i) // возвращает ссылку, но есл нет доступа то nullptr
{
    if (i < users.size())
        return users[i];
    return nullptr;
}
