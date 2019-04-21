#include "pch.h"
#include "Item.h"


Item::Item(){
	srand(time(NULL));
	hp = rand() % 30 + 5;
	damage = rand() % 30 + 5;
	turns = rand() % 5 + 1;
	special = false;
}

int Item::getHp() const{
	return hp;
}

int Item::getDamage() const{
	return damage;
}

int Item::getTurns() const{
	return turns;
}

bool Item::getSpecial() const{
	return special;
}

void Item::setSpecial() {
	special = true;
}

void Item::setTurns(int x){
	turns = x;
}

void Item::setHp(int x){
	hp = x;
}

void Item::setDamage(int x){
	damage = x;
}

void Item::Used(){
	special = false;
	hp = 0;
	damage = 0;
	turns = 0;
}
