#include "chat.h"
Chat::Chat()
{
}

Chat::~Chat()
{
}

int Chat::getChat() const
{
	return _chat;
}
void Chat::setChat(int chat)
{
	_chat = chat;
}

void Chat::LocalChat(UserStorage& object, int counter)
{
	for(int i = 0; i < counter; i++)
	{
		//cout << object[i]->get_num() <<"|" << object[i]->get_name() << "|" << endl;
	}
	selectUser(object);
	// .. отправка сообщения
}

void  Chat::GlobalChat()
{
	// .. отправка сообщения
}

void Chat::selectUser(UserStorage& object)
{
	int number;
	cin >> number;
	//cout <<	object[number]->get_login();
}

void Chat::selectChat(Chat &object, UserStorage& object2, int counter)
{
	short idxOfChat;
	cout << "Select Chat: ";
	cin >> idxOfChat;
	object.setChat(idxOfChat);
	switch (idxOfChat)
	{
	case 1:
		LocalChat(object2, counter);
		break;
	case 2:
		GlobalChat();
		break;
	default:
		break;
	}
}
