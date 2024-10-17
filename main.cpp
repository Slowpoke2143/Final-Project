#include <iostream>
#include <string>
#include "Chat.h"
#include "User.h"
#include "UserStorage.h"
using namespace std;

int main() 
{
	string name;
	string password;
	string login;
	UserStorage userstorage;
	Chat chat;
	int regUser = 1;
	static int i = 0;
	while(i < 2)
	{
		cin >> login >> password >> name;
		userstorage.registerUser(i, login, password, name);
		cout << "succses" << endl;
		i++;
	}
		chat.selectChat(chat, userstorage, i);

}
