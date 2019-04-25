#pragma once
#include "Agent.h"
class Agent_3 : public Agent{
	Agent_3();
	~Agent_3();
	// implementare functii virtuale
	string move(Map&);
	void SetItem(Item);
	void SpecialItem();
	friend class Game;
};

