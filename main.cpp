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
	setlocale(LC_ALL, "ru");
	UserStorage userstorage; // классы чисто для взаимодействия
	LMStorage lmstorage; // хранилище локальных сообщений
	GlobalMessage globalMessage(&userstorage); // хранилище глобальных сообщений
	//Chat chat;

	for (int i = 0; i < 3; i++)
	{
		string name;
		string password;
		string login;
		cout << "введи login password name: ";
		cin >> login >> password >> name;
		if (!userstorage.registerUser(login, password, name)) // проверка на регистрацию
		{
			cout << "такой логин уже есть, так что бывай ;)" << endl;
			return -1;
		}
		cout << "succses" << endl;
	}
	// локальный чат
	LocalMessage lm(userstorage[0], userstorage[1]); // создаем локальный чат между двумя пользователями
	string m;
	cout << "введи сообщение от первого пользователя: ";
	cin >> m; 
	lm.SendMessage(userstorage[0]->get_login(), m); // отправляем сообщение от имени введенного пользователя
	cout << "введи сообщение от второго пользователя: ";
	cin >> m;
	lm.SendMessage(userstorage[1]->get_login(), m); // отправляем сообщение от имени введенного пользователя
	lm.PrintAllMessage(); // выводим все сообщения в этом чате
	lmstorage.addLM(&lm); // добавляем эту переписку в хранилище локальных переписок
	
	// глобальный чат
	cout << "введи сообщение от первого пользователя: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[0]->get_login(), m);

	cout << "введи сообщение от второго пользователя: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[1]->get_login(), m);

	cout << "введи сообщение от третьего пользователя: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[2]->get_login(), m);

	globalMessage.PrintAll();


	cout << "end" << endl;
}
