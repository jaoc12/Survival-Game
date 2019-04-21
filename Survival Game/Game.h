#pragma once

#include "Map.h"
#include "Agent.h"
#include "Agent_1.h"
#include "Agent_2.h"
#include "Agent_3.h"

class Game{
	Game();
	~Game();
	void SetupMap(Map&);
	void SetupItem(Map&, vector<Item>&);
	void SetupAgent(Map&, vector<Agent*>&, vector<Item>&);
	void SetupAgent1(Map&, int, vector<Agent*>&, vector<Item>&);
	void SetupAgent2(Map&, int, vector<Agent*>&, vector<Item>&);
	void SetupAgent3(Map&, int, vector<Agent*>&, vector<Item>&);
	void Setup(Map&, vector<Item>&, vector<Agent*>&);
	void Move(Map&, vector<Agent*>&, Agent*, string);
	void MoveItem(Map&, vector<Agent*>&, Agent*, string, vector<Item>&);
	void Battle(Map&, vector<Agent*>&, Agent*, string, vector<Item>&);
	bool Turn(Map&, vector<Item>&, vector<Agent*>&);
	void Play();
	friend void start();
};

