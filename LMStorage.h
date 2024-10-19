#pragma once
#include"LocalMessage.h"
#include<vector>
class LMStorage
{
private:
	std::vector<LocalMessage*> lms;
public:
	LMStorage() = default;
	~LMStorage() = default;

	void addLM(LocalMessage* lm);

	std::vector<LocalMessage*> getAllLM(std::string login);
	LocalMessage* getLM(std::string login1, std::string login2);
};

