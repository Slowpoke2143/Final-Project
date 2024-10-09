#pragma once
#include <iostream>
#include <string>
#include <memory>
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

	void LocalChat();
	void selectChat(Chat &object);

	
};

