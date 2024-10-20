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
	UserStorage userstorage; // ������ ����� ��� ��������������
	LMStorage lmstorage; // ��������� ��������� ���������
	GlobalMessage globalMessage(&userstorage); // ��������� ���������� ���������
	//Chat chat;

	for (int i = 0; i < 3; i++)
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
	// ��������� ���
	LocalMessage lm(userstorage[0], userstorage[1]); // ������� ��������� ��� ����� ����� ��������������
	string m;
	cout << "����� ��������� �� ������� ������������: ";
	cin >> m; 
	lm.SendMessage(userstorage[0]->get_login(), m); // ���������� ��������� �� ����� ���������� ������������
	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	lm.SendMessage(userstorage[1]->get_login(), m); // ���������� ��������� �� ����� ���������� ������������
	lm.PrintAllMessage(); // ������� ��� ��������� � ���� ����
	lmstorage.addLM(&lm); // ��������� ��� ��������� � ��������� ��������� ���������
	
	// ���������� ���
	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[0]->get_login(), m);

	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[1]->get_login(), m);

	cout << "����� ��������� �� �������� ������������: ";
	cin >> m;
	globalMessage.SendMessage(userstorage[2]->get_login(), m);

	globalMessage.PrintAll();


	cout << "end" << endl;
}
