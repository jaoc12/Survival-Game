#pragma once

#include <stdlib.h>
#include <time.h>  

class Item{
	int hp, damage, turns;
	bool special;
public:
	Item();
	int getHp() const;
	int getDamage() const;
	int getTurns() const;
	bool getSpecial() const;
	void setSpecial();
	void setTurns(int);
	void setHp(int);
	void setDamage(int);
	void Used();
};

