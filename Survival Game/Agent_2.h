#pragma once
#include "Agent.h"
class Agent_2 : public Agent{
	Agent_2();
	~Agent_2();
	// implementare functii virtuale
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
	friend class Game;
};

