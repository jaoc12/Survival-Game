#pragma once
#include "Agent.h"
class Agent_2 : public Agent{
public:
	Agent_2();
	~Agent_2();
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
};

