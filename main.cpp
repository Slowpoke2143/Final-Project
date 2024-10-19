#include <iostream>
#include <string>
#include "Chat.h"
#include "User.h"
#include "LMStorage.h"
#include "UserStorage.h"
#include "LocalMessage.h"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");
	UserStorage userstorage; // ������ ����� ��� ��������������
	LMStorage lmstorage;
	//Chat chat;

	for (int i = 0; i < 2; i++)
	{
		string name;
		string password;
		string login;
		cout << "����� login password name: ";
		cin >> login >> password >> name;
		if (!userstorage.registerUser(login, password, name)) // �������� �� �����������
		{
			cout << "����� ����� ��� ����, ��� ��� ����� ;)" << endl;
			return -1;
		}
		cout << "succses" << endl;
	}
	LocalMessage lm(userstorage[0], userstorage[1]);
	string m;
	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	lm.SendMessage(userstorage[0]->get_login(), m);
	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	lm.SendMessage(userstorage[1]->get_login(), m);
	lm.PrintAllMessage();
	lmstorage.addLM(&lm);
	cout << "end" << endl;
}
