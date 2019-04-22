#include "pch.h"
#include "Agent_3.h"


Agent_3::Agent_3() : Agent(70, 70) {}

Agent_3::~Agent_3() {

}

string Agent_3::move(Map &m) {
	string s;
	//Dreapta sus
	if ((poz_x - 2 >= 0) && (poz_y + 1 < m.n)) {
		if (m.map[poz_x - 2][poz_y + 1][0] == 'A') {
			s = "B" + to_string(poz_x - 2) + "-" + to_string(poz_y + 1);
			return s;
		}
		if (m.map[poz_x - 2][poz_y + 1][0] == 'I') {
			s = "I" + to_string(poz_x - 2) + "-" + to_string(poz_y + 1);
			return s;
		}
		s = "M" + to_string(poz_x - 2) + "-" + to_string(poz_y + 1);
		return s;
	}
	//Stanga sus
	if ((poz_x - 2 >= 0) && (poz_y - 1 >= 0)) {
		if (m.map[poz_x - 2][poz_y - 1][0] == 'A') {
			s = "B" + to_string(poz_x - 2) + "-" + to_string(poz_y - 1);
			return s;
		}
		if (m.map[poz_x - 2][poz_y - 1][0] == 'I') {
			s = "I" + to_string(poz_x - 2) + "-" + to_string(poz_y - 1);
			return s;
		}
		s = "M" + to_string(poz_x - 2) + "-" + to_string(poz_y - 1);
		return s;
	}
	//Dreapta jos
	if ((poz_x + 2 < m.m) && (poz_y + 1 < m.n)) {
		if (m.map[poz_x + 2][poz_y + 1][0] == 'A') {
			s = "B" + to_string(poz_x + 2) + "-" + to_string(poz_y + 1);
			return s;
		}
		if (m.map[poz_x + 2][poz_y + 1][0] == 'I') {
			s = "I" + to_string(poz_x + 2) + "-" + to_string(poz_y + 1);
			return s;
		}
		s = "M" + to_string(poz_x + 2) + "-" + to_string(poz_y + 1);
		return s;
	}
	//Stanga jos
	if ((poz_x + 2 < m.m) && (poz_y - 1 >= 0)) {
		if (m.map[poz_x + 2][poz_y - 1][0] == 'A') {
			s = "B" + to_string(poz_x + 2) + "-" + to_string(poz_y - 1);
			return s;
		}
		if (m.map[poz_x + 2][poz_y - 1][0] == 'I') {
			s = "I" + to_string(poz_x + 2) + "-" + to_string(poz_y - 1);
			return s;
		}
		s = "M" + to_string(poz_x + 2) + "-" + to_string(poz_y - 1);
		return s;
	}
	return "NULL";
}

void Agent_3::SetItem(Item i) {
	if (i.getTurns() > 0)
		item = i;
	item.setTurns(item.getTurns() * 3 / 2);

}

void Agent_3::SpecialItem() {
	if (item.getSpecial() == true) {
		if (base_hp > 10)
			base_hp -= 10;
		base_damage += 10;
	}
}
