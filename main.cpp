#include <iostream>
#include <string>
#include <exception>
using namespace std;

class User {
public:
    string login;
    string password;
    string name;

    User() = default;

    User(const string& login, const string& password, const string& name)
        : login(login), password(password), name(name) {}
};

class Chat {  //HZ 
private:
    User* users;
    int numUsers;

public:
    Chat() : users(nullptr), numUsers(0) {}

    ~Chat() {
        delete[] users;
    }

    void registerUser(const string& login, const string& password, const string& name) {
        User* newUsers = new User[numUsers + 1];
        for (int i = 0; i < numUsers; i++) {
            newUsers[i] = users[i];
        }
        newUsers[numUsers] = User(login, password, name);
        delete[] users;
        users = newUsers;
        numUsers++;
    }

    void login(const string& login, const string& password) {
        for (int i = 0; i < numUsers; i++) {
            if (users[i].login == login && users[i].password == password) {
                cout << "Welcome, " << users[i].name << "!" << endl;
                return;
            }
        }
        throw runtime_error("Invalid login or password");
    }
};

int main() {
    Chat chat;
    chat.registerUser("login", "password", "name");
    chat.registerUser("login1", "password1", "name1");
}
