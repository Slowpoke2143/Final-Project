#pragma once
#include <iostream>
#include <string>
#include "UserStorage.h"
using namespace std;

class Chat : UserStorage
{
private:
	int _chat = 0;
public:
	 Chat();
	~Chat();

	void setChat(int chat);
	int getChat() const;

	void LocalChat(UserStorage &object, int counter);
	void GlobalChat();
	void selectUser(UserStorage& object);
	void selectChat(Chat &object, UserStorage& object2, int counter);

	
};

