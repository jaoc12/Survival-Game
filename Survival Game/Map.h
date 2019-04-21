#pragma once

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Map{
	int m, n;
	vector<vector<string> > map;
	void Set(int, int);
	Map();
	~Map();
	void Display();
	friend class Game;
	friend class Agent_1;
	friend class Agent_2;
	friend class Agent_3;
};

