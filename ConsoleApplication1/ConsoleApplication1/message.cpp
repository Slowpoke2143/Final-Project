#include "message.h"

Chat::Chat(){}

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

void LocalChat()
{
	// список юзеров
	//..выбор юзера 
	// .. отправка сообщения
}

void GlobalChat()
{

	// .. отправка сообщения
}

void Chat::selectChat(Chat &object)
{
	short idxOfChat;
	cout << "Select Chat: ";
	cin >> idxOfChat;
	object.setChat(idxOfChat);
	switch (idxOfChat)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	system("cls");
}
