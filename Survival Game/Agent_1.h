#pragma once
#include "Agent.h"
class Agent_1 : public Agent{
public:
	Agent_1();
	~Agent_1();
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
};

