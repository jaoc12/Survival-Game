#include "pch.h"
#include "Agent_2.h"

// consturctor cu lista de initializare
Agent_2::Agent_2() : Agent(100, 50) {}

Agent_2::~Agent_2() {}

// returneaza "Bxy" daca pe pozitia xy se afla alt agent
// returneaza "Ixy" daca pe pozitia xy se afla un item
// returneaza "Mxy" daca pe pozitia xy nu se afla nimic
// returneaza "NULL" daca agentul nu se poate muta
string Agent_2::move(Map &m) {
	string s;
	//Diagonala dreapta sus
	if ((poz_x - 2 >= 0) && (poz_y + 2 < m.n)) {
		if (m.map[poz_x - 2][poz_y + 2][0] == 'A') {
			s = "B" + to_string(poz_x - 2) + "-" + to_string(poz_y + 2);
			return s;
		}
		if (m.map[poz_x - 2][poz_y + 2][0] == 'I') {
			s = "I" + to_string(poz_x - 2) + "-" + to_string(poz_y + 2);
			return s;
		}
		s = "M" + to_string(poz_x - 2) + "-" + to_string(poz_y + 2);
		return s;
	}
	//Diagonala stanga jos
	if ((poz_x + 2 < m.m) && (poz_y - 2 >= 0)) {
		if (m.map[poz_x + 2][poz_y - 2][0] == 'A') {
			s = "B" + to_string(poz_x  + 2) + "-" + to_string(poz_y - 2);
			return s;
		}
		if (m.map[poz_x + 2][poz_y - 2][0] == 'I') {
			s = "I" + to_string(poz_x + 2) + "-" + to_string(poz_y - 2);
			return s;
		}
		s = "M" + to_string(poz_x + 2) + "-" + to_string(poz_y - 2);
		return s;
	}
	//Diagonala dreapta jos
	if ((poz_x + 2 < m.m) && (poz_y + 2 < m.n)) {
		if (m.map[poz_x + 2][poz_y + 2][0] == 'A') {
			s = "B" + to_string(poz_x + 2) + "-" + to_string(poz_y + 2);
			return s;
		}
		if (m.map[poz_x + 2][poz_y + 2][0] == 'I') {
			s = "I" + to_string(poz_x + 2) + "-" + to_string(poz_y + 2);
			return s;
		}
		s = "M" + to_string(poz_x + 2) + "-" + to_string(poz_y + 2);
		return s;
	}
	//Diagonala stanga sus
	if ((poz_x - 2 >= 0) && (poz_y - 2 >= 0)) {
		if (m.map[poz_x - 2][poz_y - 2][0] == 'A') {
			s = "B" + to_string(poz_x - 2) + "-" + to_string(poz_y - 2);
			return s;
		}
		if (m.map[poz_x - 2][poz_y - 2][0] == 'I') {
			s = "I" + to_string(poz_x - 2) + "-" + to_string(poz_y - 2);
			return s;
		}
		s = "M" + to_string(poz_x - 2) + "-" + to_string(poz_y - 2);
		return s;
	}
	return "NULL";
}

// implementeaza itemul in functie de tipul agentului
void Agent_2::SetItem(Item i) {
	if (i.getTurns() > 0)
		item = i;
	item.setDamage(item.getDamage() * 3 / 2);
}

void Agent_2::SpecialItem() {
	if (item.getSpecial() == true) {
		if (base_hp <= 50)
			base_damage += 20;
	}
}
