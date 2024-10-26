#include "chat.h"
Chat::Chat() {}

Chat::~Chat(){}

int Chat::getChat() const
{
	return _chat;
}
void Chat::setChat(int chat)
{
	_chat = chat;
}

void Chat::LocalChat(UserStorage& object, int currentUser, LMStorage* lmstorage)
{
	
	for(int i = 0; i < object.get_length(); i++)
	{
		cout << object[i]->get_uniq_value() << "|" << object[i]->get_name() << "|" << endl;
	}
	int numberOfUser;
	cin >> numberOfUser;

	if (object[currentUser]->get_login() == object[numberOfUser]->get_login())
	{
		cout << "�� �� ������ ��������� ��������� ������ ����" << endl;
	}
	lmstorage->addLM(object[currentUser], object[numberOfUser]);
	lmstorage->getLM(object[currentUser]->get_login(), object[numberOfUser]->get_login())->PrintAllMessage();
	
	string m;
	//bool exit_chat = false;
	//while (!exit_chat)
	//{
	//	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;

	lmstorage->getLM(object[currentUser]->get_login(), object[numberOfUser]->get_login())->SendMessage(object[currentUser]->get_login(), m); //�� ��� ������ ������, �� ���� � ��
	lmstorage->getLM(object[currentUser]->get_login(), object[numberOfUser]->get_login())->PrintAllMessage();
	//	if (m == "q")
	//	{
	//		exit_chat = true;
	//	}
	//}
	//_localMessageStorage.addLM(&object2); // ��������� ��� ��������� � ��������� ��������� ���������
	//object2.PrintAllMessage(); // ������� ��� ��������� � ���� ����
}

void Chat::GlobalChat(UserStorage& object, int currentUser, GlobalMessage& globalMessage)
{
	globalMessage.PrintAll();
	string m;
	//bool exit_chat = false;
	//while (!exit_chat)
	//{
	//	cout << "����� ��������� �� ������� ������������: ";
	cin >> m;
	globalMessage.SendMessage(object[currentUser]->get_login(), m);
}

void Chat::selectChat(Chat &object, UserStorage &obj, int counter, LMStorage* lmstorage, GlobalMessage& globalMessage)
{
	short idxOfChat;
	cout << "Select Chat: 1 - Local, 2 - Global" << endl;
	cin >> idxOfChat;
	object.setChat(idxOfChat);
	switch (idxOfChat)
	{
	case 1:
		LocalChat(obj, counter, lmstorage);
		break;
	case 2:
		GlobalChat(obj, counter, globalMessage);
		break;
	default: 
		break;
	}
}
