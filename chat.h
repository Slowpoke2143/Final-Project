#pragma once
#include <iostream>
#include <string>
#include "UserStorage.h"
#include "LocalMessage.h"
#include "LMStorage.h"
#include "GlobalMessage.h"
using namespace std;

class Chat
{
private:
	int _chat = 0;
public:
	 Chat();
	~Chat();

	void setChat(int chat);
	int getChat() const;

	void LocalChat(UserStorage &object, int counter, LMStorage* lmstorage);
	void GlobalChat(UserStorage& object, int counter, GlobalMessage& globalMessage);

	void selectChat(Chat &object, UserStorage& obj, int counter, LMStorage *lmstorage, GlobalMessage& globalMessage);
};

