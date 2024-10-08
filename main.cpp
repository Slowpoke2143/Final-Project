#include "User.h"
#include <iostream>
#include <string>
#include "User.h"
#include "UserStorage.h"
using namespace std;

int main() {
    UserStorage userStorage;
    userStorage.registerUser("login", "password", "name");
    userStorage.registerUser("login1", "password1", "name1");
}
