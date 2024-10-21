#include <iostream>
#include <string>
#include <exception>

class User {
public:
    std::string login;
    std::string password;
    std::string name;

    User() = default;

    User(const std::string& login, const std::string& password, const std::string& name)
        : login(login), password(password), name(name) {}

    ~User() {};
};

class Chat {
private:
    User* users;
    int numUsers;

public:
    Chat() : users(nullptr), numUsers(0) {}

    ~Chat() {
        delete[] users;
    }

    void registerUser(const std::string& login, const std::string& password, const std::string& name) {
        for (int i = 0; i < numUsers; i++) {
            if (users[i].login == login) {
                throw std::runtime_error("User already exists");
            }
        }
        User* newUsers = new User[numUsers + 1];
        for (int i = 0; i < numUsers; i++) {
            newUsers[i] = users[i];
        }
        newUsers[numUsers] = User(login, password, name);
        delete[] users;
        users = newUsers;
        numUsers++;
    }

    void login(const std::string& login, const std::string& password) {
        for (int i = 0; i < numUsers; i++) {
            if (users[i].login == login && users[i].password == password) {
                std::cout << "Welcome, " << users[i].name << "!" << std::endl;
                return;
            }
        }
        throw std::runtime_error("Invalid login or password");
    }

    
};

int main() {
    Chat chat;

    std::string command;
    while (true) {
        std::cout << "Enter command (register, login, send, exit, logout): ";
        std::cin >> command;

        if (command == "register") {
            std::string login, password, name;
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "Enter password: ";
            std::cin >> password;
            std::cout << "Enter name: ";
            std::cin >> name;
            try {
                chat.registerUser(login, password, name);
                std::cout << "User registered successfully" << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "login") {
            std::string login, password;
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "Enter password: ";
            std::cin >> password;
            try {
                chat.login(login, password);
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "send") {
            std::string from, to, message;
            std::cout << "Enter sender: ";
            std::cin >> from;
            std::cout << "Enter recipient: ";
            std::cin >> to;
            std::cout << "Enter message: ";
            std::cin >> message;
            try {
                chat.sendMessage(from, to, message);
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "logout") {
            std::string login;
            std::cout << "Enter login: ";
            std::cin >> login;
            try {
                std::cout << "You logout!" << std::endl;
            }
            catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }
    return 0;