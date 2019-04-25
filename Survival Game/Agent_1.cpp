#include "pch.h"
#include "Agent_1.h"

// consturctor cu lista de initializare
Agent_1::Agent_1() : Agent(150,35) {}

Agent_1::~Agent_1() {}

// returneaza "Bxy" daca pe pozitia xy se afla alt agent
// returneaza "Ixy" daca pe pozitia xy se afla un item
// returneaza "Mxy" daca pe pozitia xy nu se afla nimic
// returneaza "NULL" daca agentul nu se poate muta
string Agent_1::move(Map &m) {
	string s;
	//Dreapta doua pozitii
	if (poz_y + 2 < m.n - 1) {
		if (m.map[poz_x][poz_y + 2][0] == 'A') {
			s = "B" + to_string(poz_x) + "-" + to_string(poz_y + 2);
			return s;
		}
		if (m.map[poz_x][poz_y + 2][0] == 'I') {
			s = "I" + to_string(poz_x) + "-" + to_string(poz_y + 2);
			return s;
		}
		s = "M" + to_string(poz_x) + "-" + to_string(poz_y + 2);
		return s;
	}
	//Jos doua pozitii
	if (poz_x + 2 < m.m - 1) {
		if (m.map[poz_x + 2][poz_y][0] == 'A') {
			s = "B" + to_string(poz_x + 2) + "-" + to_string(poz_y);
			return s;
		}
		if (m.map[poz_x + 2][poz_y][0] == 'I') {
			s = "I" + to_string(poz_x + 2) + "-" + to_string(poz_y);
			return s;
		}
		s = "M" + to_string(poz_x + 2) + "-" + to_string(poz_y);
		return s;
	}
	//Stanga doua pozitii
	if (poz_y - 2 >= 0) {
		if (m.map[poz_x][poz_y - 2][0] == 'A') {
			s = "B" + to_string(poz_x) + "-" + to_string(poz_y - 2);
			return s;
		}
		if (m.map[poz_x][poz_y - 2][0] == 'I') {
			s = "I" + to_string(poz_x) + "-" + to_string(poz_y - 2);
			return s;
		}
		s = "M" + to_string(poz_x) + "-" + to_string(poz_y - 2);
		return s;
	}
	//Sus doua pozitii
	if (poz_x - 2 >= 0) {
		if (m.map[poz_x - 2][poz_y][0] == 'A') {
			s = "B" + to_string(poz_x - 2) + "-" + to_string(poz_y);
			return s;
		}
		if (m.map[poz_x - 2][poz_y][0] == 'I') {
			s = "I" + to_string(poz_x - 2) + "-" + to_string(poz_y);
			return s;
		}
		s = "M" + to_string(poz_x - 2) + "-" + to_string(poz_y);
		return s;
	}
	return "NULL";
}

// implementeaza itemul in functie de tipul agentului
void Agent_1::SetItem(Item i) {
	if (i.getTurns() > 0)
		item = i;
	item.setTurns(item.getTurns() * 3 / 2);
}

void Agent_1::SpecialItem() {
	if (item.getSpecial() == true) {
		if (base_hp != 150)
			base_hp += 35;
	}
}
