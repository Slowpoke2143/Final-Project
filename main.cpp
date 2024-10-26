#include <iostream>
#include <string>
#include "Chat.h"
#include "User.h"
#include "LMStorage.h"
#include "UserStorage.h"
#include "LocalMessage.h"
#include "GlobalMessage.h"
using namespace std;

int main()
{
	bool exit = false;
	short cmd;
	setlocale(LC_ALL, "ru");
	UserStorage userstorage; // классы чисто для взаимодействия
	LMStorage lmstorage; // хранилище локальных сообщений
	GlobalMessage globalMessage(&userstorage); // хранилище глобальных сообщений
	
	Chat chat;

	

	static int counter_of_users = 0;
	string name;
	string password;
	string login;
	cout << "1 - registration, 2 - login, 0 - exit" << endl;
	while(!exit)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cout << "введи login password name: ";
			cin >> login >> password >> name;
			if (!userstorage.registerUser(login, password, name, counter_of_users)) // проверка на регистрацию
			{
				cout << "такой логин уже есть, так что бывай ;)" << endl;
				return -1;
			}
			counter_of_users++;
			cout <<"succses" << endl;
			break;
		case 2:
			cout << "вход: ";
			cin >> login >> password;
			if (userstorage.login(login, password))
			{
				cout << "Успешный вход" << endl;
				bool exit_chat = false;
				while (!exit_chat)
				{
					User* current_user = userstorage.login(login, password);
					chat.selectChat(chat, userstorage, (current_user->get_uniq_value()), &lmstorage, globalMessage);
					cout << "Хотите выйти?" << endl;
					cin >> exit_chat;
				}
			}
			else
			{
				break;
			}
			break;
		case 0:
			exit = 1;
			break;
		default:
			cout << "Something went wrong" << endl;
			break;
		}
	}
	// локальный чат
	//LocalMessage lm(userstorage[0], userstorage[1]); // создаем локальный чат между двумя пользователями
	//string m;
	//cout << "введи сообщение от первого пользователя: ";
	//cin >> m; 
	//lm.SendMessage(userstorage[0]->get_login(), m); // отправляем сообщение от имени введенного пользователя
	//cout << "введи сообщение от второго пользователя: ";
	//cin >> m;
	//lm.SendMessage(userstorage[1]->get_login(), m); // отправляем сообщение от имени введенного пользователя
	//lm.PrintAllMessage(); // выводим все сообщения в этом чате
	//lmstorage.addLM(&lm); // добавляем эту переписку в хранилище локальных переписок
	
	//// глобальный чат
	//cout << "введи сообщение от первого пользователя: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[0]->get_login(), m);

	//cout << "введи сообщение от второго пользователя: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[1]->get_login(), m);

	//cout << "введи сообщение от третьего пользователя: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[2]->get_login(), m);

	//globalMessage.PrintAll();


	cout << "end" << endl;
}
