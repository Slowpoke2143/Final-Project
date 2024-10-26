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
	UserStorage userstorage; // ������ ����� ��� ��������������
	LMStorage lmstorage; // ��������� ��������� ���������
	GlobalMessage globalMessage(&userstorage); // ��������� ���������� ���������
	
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
			cout << "����� login password name: ";
			cin >> login >> password >> name;
			if (!userstorage.registerUser(login, password, name, counter_of_users)) // �������� �� �����������
			{
				cout << "����� ����� ��� ����, ��� ��� ����� ;)" << endl;
				return -1;
			}
			counter_of_users++;
			cout <<"succses" << endl;
			break;
		case 2:
			cout << "����: ";
			cin >> login >> password;
			if (userstorage.login(login, password))
			{
				cout << "�������� ����" << endl;
				bool exit_chat = false;
				while (!exit_chat)
				{
					User* current_user = userstorage.login(login, password);
					chat.selectChat(chat, userstorage, (current_user->get_uniq_value()), &lmstorage, globalMessage);
					cout << "������ �����?" << endl;
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
	// ��������� ���
	//LocalMessage lm(userstorage[0], userstorage[1]); // ������� ��������� ��� ����� ����� ��������������
	//string m;
	//cout << "����� ��������� �� ������� ������������: ";
	//cin >> m; 
	//lm.SendMessage(userstorage[0]->get_login(), m); // ���������� ��������� �� ����� ���������� ������������
	//cout << "����� ��������� �� ������� ������������: ";
	//cin >> m;
	//lm.SendMessage(userstorage[1]->get_login(), m); // ���������� ��������� �� ����� ���������� ������������
	//lm.PrintAllMessage(); // ������� ��� ��������� � ���� ����
	//lmstorage.addLM(&lm); // ��������� ��� ��������� � ��������� ��������� ���������
	
	//// ���������� ���
	//cout << "����� ��������� �� ������� ������������: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[0]->get_login(), m);

	//cout << "����� ��������� �� ������� ������������: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[1]->get_login(), m);

	//cout << "����� ��������� �� �������� ������������: ";
	//cin >> m;
	//globalMessage.SendMessage(userstorage[2]->get_login(), m);

	//globalMessage.PrintAll();


	cout << "end" << endl;
}
