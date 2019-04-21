#include "pch.h"
#include "Game.h"


Game::Game(){
	cout << "Sesiune noua de joc inceputa" << endl;
}

Game::~Game() {
	cout << "Sesiune de joc terminata" << endl;
}

void Game::SetupMap(Map &m) {
	int x, y;
	cout << "Ce dimensiune sa aiba harta?" << endl << "Minimul este de 15*15" << endl;
	cin >> x >> y;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Caracterul introdus nu este un numar in baza 10" << endl;
		x = y = 0;
	}
	while (x < 15 || y < 15) {
		cout << "Dimensiunile sunt prea mici" << endl;
		cin >> x >> y;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Caracterul introdus nu este un numar in baza 10" << endl;
			x = y = 0;
		}
	}
	m.Set(x, y);
}

void Game::SetupItem(Map &m, vector<Item> &v_item) {
	int n, x, y, count;
	x = m.m;
	y = m.n;
	cout << "Cate iteme sa fie pe harta?" << endl;
	cin >> n;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Caracterul introdus nu este un numar in baza 10" << endl;
		n = x * y + 1;
	}
	while (n > x*y) {
		cout << "Prea multe iteme pentru dimensiunea hartii" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Caracterul introdus nu este un numar in baza 10" << endl;
			n = x * y + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		Item temp;
		v_item.push_back(temp);
	}
	count = 0;
	while (count < n) {
		if (n % 10 == 0)
			v_item[count].setSpecial();
		int i, j;
		i = rand() % x;
		j = rand() % y;
		if (m.map[i][j] == "-") {
			if (count < 10) {
				m.map[i][j] = "I0" + to_string(count);
			}
			else {
				m.map[i][j] = "I" + to_string(count);
			}
			count++;
		}
	}
}

void Game::SetupAgent1(Map&m, int n, vector<Agent*> &v_agent, vector<Item> &v_item) {
	int count, x, y;
	x = m.m;
	y = m.n;
	count = 0;
	while (count < n) {
		int i, j, k;
		i = rand() % x;
		j = rand() % y;
		if (m.map[i][j][0] != 'A') {
			v_agent[count]->poz_x = i;
			v_agent[count]->poz_y = j;
			string flag;
			if (m.map[i][j] == "-")
				flag = "-";
			else {
				k = (m.map[i][j][1] - '0') * 10 + (m.map[i][j][2] - '0');
				v_agent[count]->SetItem(v_item[k]);
				flag = "+";
			}
			if (count < 10) {
				m.map[i][j] = "A10" + to_string(count) + flag;
			}
			else {
				m.map[i][j] = "A1" + to_string(count) + flag;
			}
			if (flag == "+")
				cout << "Agentul " << m.map[i][j] << " a obtinut itemul I" << k << endl;
			count++;
		}
	}
}

void Game::SetupAgent2(Map&m, int n, vector<Agent*> &v_agent, vector<Item> &v_item) {
	int count, x, y;
	x = m.m;
	y = m.n;
	count = 0;
	while (count < n) {
		int i, j, k;
		i = rand() % x;
		j = rand() % y;
		if (m.map[i][j][0] != 'A') {
			v_agent[count + n]->poz_x = i;
			v_agent[count + n]->poz_y = j;
			string flag;
			if (m.map[i][j] == "-")
				flag = "-";
			else {
				k = (m.map[i][j][1] - '0') * 10 + (m.map[i][j][2] - '0');
				v_agent[count + n]->SetItem(v_item[k]);
				flag = "+";
			}
			if (count < 10) {
				m.map[i][j] = "A20" + to_string(count) + flag;
			}
			else {
				m.map[i][j] = "A2" + to_string(count) + flag;
			}
			if (flag == "+")
				cout << "Agentul " << m.map[i][j] << " a obtinut itemul I" << k << endl;
			count++;
		}
	}
}

void Game::SetupAgent3(Map&m, int n, vector<Agent*> &v_agent, vector<Item> &v_item) {
	int count, x, y;
	x = m.m;
	y = m.n;
	count = 0;
	while (count < n) {
		int i, j, k;
		i = rand() % x;
		j = rand() % y;
		if (m.map[i][j][0] != 'A') {
			v_agent[count + 2 * n]->poz_x = i;
			v_agent[count + 2 * n]->poz_y = j;
			string flag;
			if (m.map[i][j] == "-")
				flag = "-";
			else {
				k = (m.map[i][j][1] - '0') * 10 + (m.map[i][j][2] - '0');
				v_agent[count + 2 * n]->SetItem(v_item[k]);
				flag = "+";
			}
			if (count < 10) {
				m.map[i][j] = "A30" + to_string(count) + flag;
			}
			else {
				m.map[i][j] = "A3" + to_string(count) + flag;
			}
			if (flag == "+")
				cout << "Agentul " << m.map[i][j] << " a obtinut itemul I" << k << endl;
			count++;
		}
	}
}

void Game::SetupAgent(Map&m, vector<Agent*> &v_agent, vector<Item> &v_item) {
	int x, y, n;
	x = m.m;
	y = m.n;
	cout << "Cati agenti de fiecare tip sa fie pe harta?" << endl << "Minimul este de 7" << endl;
	cin >> n;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Caracterul introdus nu este un numar in baza 10" << endl;
		n = x * y;
	}
	while (n * 3 > x*y) {
		cout << "Prea multi agenti pentru dimensiunea hartii si numarul de iteme" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Caracterul introdus nu este un numar in baza 10" << endl;
			n = x * y;
		}
	}
	for (int i = 0; i < n; i++) {
		Agent *temp1 = new Agent_1;
		v_agent.push_back(temp1);
	}
	for (int i = 0; i < n; i++) {
		Agent *temp2 = new Agent_2;
		v_agent.push_back(temp2);
	}
	for (int i = 0; i < n; i++) {
		Agent *temp3 = new Agent_3;
		v_agent.push_back(temp3);
	}
	SetupAgent1(m, n, v_agent, v_item);
	SetupAgent2(m, n, v_agent, v_item);
	SetupAgent3(m, n, v_agent, v_item);
}

void Game::Setup(Map &m, vector<Item> &v_item, vector<Agent*> &v_agent) {
	srand(time(NULL));
	SetupMap(m);
	SetupItem(m, v_item);
	SetupAgent(m, v_agent, v_item);
}

void coordonate(int &x, int &y, string s) {
	x = y = 0;
	for (int i = 1; i < 3; i++) {
		if (s[i] != '-')
			x = x * 10 + (s[i] - '0');
	}
	for (int i = 3; i < s.length(); i++) {
		if (s[i] != '-')
			y = y * 10 + (s[i] - '0');
	}
}

void Game::Move(Map &m, vector<Agent*> &v_agent, Agent* i, string s) {
	int x, y;
	coordonate(x, y,s);
	m.map[x][y] = m.map[i->poz_x][i->poz_y];
	m.map[i->poz_x][i->poz_y] = "-";
	cout << "Agentul " << m.map[x][y] << " s-a mutat de pe pozitia "
		<< i->poz_x << "-" << i->poz_y << " pe pozitia " << x << "-" << y << " ";
	i->poz_x = x;
	i->poz_y = y;
}

void Game::MoveItem(Map &m, vector<Agent*> &v_agent, Agent* i, string s, vector<Item> &v_item) {
	int x, y, k;
	coordonate(x, y, s);
	k = (m.map[x][y][1] - '0') * 10 + (m.map[x][y][2] - '0');
	if (v_item[k].getTurns() > i->item.getTurns())
		i->SetItem(v_item[k]);
	Move(m, v_agent, i, s);
	cout << "si a obtinut itemul " << "I" << k;
}

void Game::Battle(Map &m, vector<Agent*> &v_agent, Agent* i, string s, vector<Item> &v_item) {
	int x, y, k, t, p;
	coordonate(x, y, s);
	p = (m.map[x][y][2] - '0') * 10 + (m.map[x][y][3] - '0');
	t = (m.map[x][y][1] - '0' - 1)*(v_agent.size() / 3);
	k = p + t;
	t = m.map[x][y][1] - '0';
	while (true) {
		i->SpecialItem();
		v_agent[k]->SpecialItem();
		if (v_agent[k]->item.getHp() > 0) {
			v_agent[k]->item.setHp(v_agent[k]->item.getHp() - (i->base_damage + i->item.getDamage()));
			i->item.setTurns(i->item.getTurns() - 1);
		}
		else{
			v_agent[k]->base_hp = v_agent[k]->base_hp - (i->base_damage + i->item.getDamage());
			i->item.setTurns(i->item.getTurns() - 1);
			if (v_agent[k]->base_hp <= 0) {
				if (v_agent[k]->item.getTurns() > i->item.getTurns()) {
					i->SetItem(v_agent[k]->item);
					m.map[i->poz_x][i->poz_y][4] = '+';
				}
				string temp = m.map[x][y];
				Move(m, v_agent, i, s);
				cout << " si l-a infrant pe agentul " << temp;
				break;
			}
		}
		if (i->item.getTurns() == 0) {
			i->item.Used();
			m.map[i->poz_x][i->poz_y][4] = '-';
		}
		if (i->item.getHp() > 0) {
			i->item.setHp(i->item.getHp() - (v_agent[k]->base_damage + v_agent[k]->item.getDamage()));
			v_agent[k]->item.setTurns(v_agent[k]->item.getTurns() - 1);
		}
		else {
			i->base_hp = i->base_hp - (v_agent[k]->base_damage + v_agent[k]->item.getDamage());
			v_agent[k]->item.setTurns(v_agent[k]->item.getTurns() - 1);
			if (i->base_hp <= 0) {
				if (i->item.getTurns() > v_agent[k]->item.getTurns()) {
					v_agent[k]->SetItem(i->item);
					m.map[x][y][4] = '+';
				}
				cout << "Agentul " << m.map[i->poz_x][i->poz_y] 
					<< " a incercat sa se mute de pe pozitia "
					<< i->poz_x << "-" << i->poz_y << " pe pozitia " << x << "-" << y
					<< " dar a fost infrant de agentul " << m.map[x][y];
				m.map[i->poz_x][i->poz_y] = "-";
				break;
			}
		}
		if (v_agent[k]->item.getTurns() == 0) {
			m.map[x][y][4] = '-';
			v_agent[k]->item.Used();
		}
	}
}

bool Game::Turn(Map &m, vector<Item> &v_item, vector<Agent*> &v_agent) {
	for (vector<Agent*>::iterator i = v_agent.begin(); i != v_agent.end(); i++) {
		if ((*i)->base_hp > 0) {
			string s = (*i)->move(m);
			//cout << &(*i) << " " << s << " " << m.m;
			if (s[0] == 'M') {
				Move(m, v_agent, *i, s);
			}
			if (s[0] == 'I') {
				MoveItem(m, v_agent, *i, s, v_item);
			}
			if (s[0] == 'B') {
				Battle(m, v_agent, *i, s, v_item);
			}
			if (s[0] == 'N') {
				cout << "Agentul " << m.map[(*i)->poz_x][(*i)->poz_y] << " nu s-a putut muta";
			}
			cout << endl;
			if (((*i)->poz_x >= m.m) || ((*i)->poz_y >= m.n)) {
				cout << "Agentul " << m.map[(*i)->poz_x][(*i)->poz_y] << " a murit deoarece "
					<< "se afla in afara hartii" << endl;
				(*i)->base_hp = 0;
			}
		}
	}
	int count = 0;
	cout << "Mai sunt in viata: ";
	for (vector<Agent*>::iterator i = v_agent.begin(); i != v_agent.end(); i++) {
		if ((*i)->base_hp > 0) {
			cout << m.map[(*i)->poz_x][(*i)->poz_y] << " ";
			count++;
		}
	}
	cout << endl;
	if (count == 1) {
		return true;
	}
	return false;
}

void Game::Play() {
	int nr=1;
	string flag;
	Map m;
	vector<Item> v_item;
	vector<Agent*> v_agent;
	Setup(m, v_item, v_agent);
	cout << "Harta dupa tura 1 este:" << endl;
	m.Display();
	do {
		cout << "Doriti simularei unei alte ture? DA-1 NU-2" << endl;
		cin >> flag;
		if (flag == "DA" || flag == "Da" || flag == "da") {
			flag = "1";
		}
		if (flag == "NU" || flag == "Nu" || flag == "nu") {
			flag = "2";
		}
		if (flag == "1") {
			nr++;
			if (Turn(m, v_item, v_agent) == false) {
				cout << "Harta dupa tura " << nr << " este:" << endl;
				m.Display();
				m.m--;
				m.n--;
			}
			else {
				cout << "Dupa " << nr << " ture avem un castigator" << endl;
				m.Display();
				flag = "2";
			}
		}
		else if (flag != "2") {
			cout << "Comanda invalida" << endl;
			}
	} while (flag != "2");
}

