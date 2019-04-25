#pragma once
#include "Agent.h"
class Agent_1 : public Agent{
	Agent_1();
	~Agent_1();
	// implementare functii virtuale
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
	friend class Game;
};

