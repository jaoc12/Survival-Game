#pragma once
#include "Agent.h"
class Agent_3 : public Agent{
public:
	Agent_3();
	~Agent_3();
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
};

