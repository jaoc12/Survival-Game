#include "pch.h"
#include "Agent.h"


Agent::Agent(int h, int d) {
	base_hp = h;
	base_damage = d;
}


Agent::~Agent()
{
}

int Agent::getHp() const{
	return base_hp;
}