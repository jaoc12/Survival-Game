#pragma once

#include "Item.h"
#include "Map.h"
#include <string>
using namespace std;

class Agent{
protected:
	int base_hp, base_damage, poz_x, poz_y;
	Item item;
	Agent(int, int);
	//destructor virtual
	virtual ~Agent();
	// functii virtuale pure
	string virtual move(Map&) = 0;
	void virtual SetItem(Item) = 0;
	void virtual SpecialItem() = 0;
	friend class Game;
};

