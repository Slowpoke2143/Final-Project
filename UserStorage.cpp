#include "UserStorage.h"

UserStorage::UserStorage() : users(nullptr), numUsers(0) {}

UserStorage::~UserStorage() {
    delete[] users;
}

void UserStorage::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    User* newUsers = new User[numUsers + 1];
    for (int i = 0; i < numUsers; i++) {
        newUsers[i] = users[i];
    }
    newUsers[numUsers] = User(login, password, name);
    delete[] users;
    users = newUsers;
    numUsers++;
}

int UserStorage::login(const std::string& login, const std::string& password) {
    for (int i = 0; i < numUsers; i++) {
        if (users[i].login == login && users[i].password == password) {
            std::cout << "Welcome, " << users[i].name << "!" << std::endl;
            return 0;
        }
    }
    return 1;
}