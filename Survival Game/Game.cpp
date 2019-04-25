#include "pch.h"
#include "Game.h"

// constuctorul si destructorul doar afiseaza mesaje
Game::Game(){
	cout << "Sesiune noua de joc inceputa" << endl;
}

Game::~Game() {
	cout << "Sesiune de joc terminata" << endl;
}

void Game::SetupMap(Map &m) {
	int x, y;
	// citeste dimensiunea si verifica sa fie de minim 15*15
	// si ca datele sa fie de tip int
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
	// apeleaza functia de facut harta
	m.Set(x, y);
}

void Game::SetupItem(Map &m, vector<Item> &v_item) {
	int n, x, y, count;
	x = m.m;
	y = m.n;
	// citeste cate iteme sa fie pe harta, fara minim, dar maxim cat are harta dimensiune
	// si ca datele sa fie de tip int
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
	// punem itemele intr-un vector
	for (int i = 0; i < n; i++) {
		Item temp;
		v_item.push_back(temp);
	}
	count = 0;
	// itemele sunt puse la intamplare pe harta
	// unul din zece este facut special
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
	// agentii sunt pusi pe harta
	// se verifica daca pe pozitia lor se afla deja un item sau alt agent
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
				// conversii ca sa aflam al catelea item se afla pe pozitie
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

// analog cu SetupAgent1
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

// analog cu SetupAgent1
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
	// citeste cati agenti sa fie pe harta, minim 7, maxim dimensiunea hartii
	// si ca datele sa fie de tip int
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
	// punem n agenti de toate tipurile intr-un vector de tip pointer de clasa de baza
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
	// agentii sunt pusi pe harta
	SetupAgent1(m, n, v_agent, v_item);
	SetupAgent2(m, n, v_agent, v_item);
	SetupAgent3(m, n, v_agent, v_item);
}

// functie care se ocupa de crearea primei ture
void Game::Setup(Map &m, vector<Item> &v_item, vector<Agent*> &v_agent) {
	srand(time(NULL));
	SetupMap(m);
	SetupItem(m, v_item);
	SetupAgent(m, v_agent, v_item);
}

// functie ajutatoare calcularea coordonatelor date de un string 
// de forma "Bxy" sau asemanator
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

// functie care muta agentul i de pe pozitia lui
// pe pozitia data de coordonatele din stringul s
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

// functie care muta un agent, avand grija sa-l echipeze cu
// itemul de pe noua pozitie, daca acesta are mai multe ture disponibile
void Game::MoveItem(Map &m, vector<Agent*> &v_agent, Agent* i, string s, vector<Item> &v_item) {
	int x, y, k;
	coordonate(x, y, s);
	k = (m.map[x][y][1] - '0') * 10 + (m.map[x][y][2] - '0');
	if (v_item[k].getTurns() > i->item.getTurns())
		i->SetItem(v_item[k]);
	// pentru mutarea propriu-zisa apeleaza functia deja definita
	Move(m, v_agent, i, s);
	cout << "si a obtinut itemul " << "I" << k;
}

// functie pentru bataia dintre doi agenti, cand unul se muta pe pozitia altuia
void Game::Battle(Map &m, vector<Agent*> &v_agent, Agent* i, string s, vector<Item> &v_item) {
	int x, y, k, t, p;
	coordonate(x, y, s);
	p = (m.map[x][y][2] - '0') * 10 + (m.map[x][y][3] - '0');
	t = (m.map[x][y][1] - '0' - 1)*(v_agent.size() / 3);
	// k este numarul agentului pe pozitia caruia se muta agentul i
	k = p + t;
	while (true) {
		// se aplica efectul itemelor speciale, daca este cazul
		i->SpecialItem();
		v_agent[k]->SpecialItem();
		// prima data ataca cel ce vrea sa se mute
		// prima data ataca hp-ul itemului
		if (v_agent[k]->item.getHp() > 0) {
			v_agent[k]->item.setHp(v_agent[k]->item.getHp() - (i->base_damage + i->item.getDamage()));
			i->item.setTurns(i->item.getTurns() - 1);
			// daca itemul nu mai are ture devine inutil
			if (i->item.getTurns() == 0) {
				i->item.Used();
				m.map[i->poz_x][i->poz_y][4] = '-';
			}
		}
		else{
			v_agent[k]->base_hp = v_agent[k]->base_hp - (i->base_damage + i->item.getDamage());
			i->item.setTurns(i->item.getTurns() - 1);
			// agentul atacat moare cand are viata sub sau egal cu zero
			if (v_agent[k]->base_hp <= 0) {
				// agentul invingator ia itemul celui invins
				// daca acesta are mai multe ture valabile
				if (v_agent[k]->item.getTurns() > i->item.getTurns()) {
					i->SetItem(v_agent[k]->item);
					m.map[i->poz_x][i->poz_y][4] = '+';
				}
				string temp = m.map[x][y];
				// folosim functia deja existenta pentru a muta agentul efectiv
				Move(m, v_agent, i, s);
				cout << " si l-a infrant pe agentul " << temp;
				// daca itemul nu mai are ture devine inutil
				if (i->item.getTurns() == 0) {
					i->item.Used();
					m.map[i->poz_x][i->poz_y][4] = '-';
				}
				// iesim din while
				break;
			}
		}
		// analog cu mai sus
		// singura diferenta este cine ataca
		if (i->item.getHp() > 0) {
			i->item.setHp(i->item.getHp() - (v_agent[k]->base_damage + v_agent[k]->item.getDamage()));
			v_agent[k]->item.setTurns(v_agent[k]->item.getTurns() - 1);
			if (v_agent[k]->item.getTurns() == 0) {
				m.map[x][y][4] = '-';
				v_agent[k]->item.Used();
			}
		}
		else {
			i->base_hp = i->base_hp - (v_agent[k]->base_damage + v_agent[k]->item.getDamage());
			v_agent[k]->item.setTurns(v_agent[k]->item.getTurns() - 1);
			if (i->base_hp <= 0) {
				if (i->item.getTurns() > v_agent[k]->item.getTurns()) {
					v_agent[k]->SetItem(i->item);
					m.map[x][y][4] = '+';
				}
				// daca cel care vrea sa se mute moare
				// se afiseaza un mesaj corespunzator si pe pozitia sa se considera libera
				cout << "Agentul " << m.map[i->poz_x][i->poz_y] 
					<< " a incercat sa se mute de pe pozitia "
					<< i->poz_x << "-" << i->poz_y << " pe pozitia " << x << "-" << y
					<< " dar a fost infrant de agentul " << m.map[x][y];
				m.map[i->poz_x][i->poz_y] = "-";
				if (v_agent[k]->item.getTurns() == 0) {
					m.map[x][y][4] = '-';
					v_agent[k]->item.Used();
				}
				break;
			}
		}
	}
}

int Game::Turn(Map &m, vector<Item> &v_item, vector<Agent*> &v_agent) {
	// iteram prin vectorul de agenti
	for (vector<Agent*>::iterator i = v_agent.begin(); i != v_agent.end(); i++) {
		if ((*i)->base_hp > 0) {
			// daca este in viata verificam unde poate agenul sa se mute
			string s = (*i)->move(m);
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
			// daca dupa mutare agentul ajunge pe o pozitie
			// care nu este pe harta il eliminam
			if (((*i)->poz_x >= m.m) || ((*i)->poz_y >= m.n)) {
				// verificam sa nu fi fost eliminat in timpul unei batalii
				if ((*i)->base_hp > 0) {
					cout << "Agentul " << m.map[(*i)->poz_x][(*i)->poz_y] << " a murit deoarece "
						<< "se afla in afara hartii" << endl;
				}
				(*i)->base_hp = 0;
			}
		}
	}
	int count = 0;
	// mai iteram prin vector sa numaram si sa afisam
	// cati agenti sunt in viata la sfarsitul turei
	cout << "Mai sunt in viata: ";
	for (vector<Agent*>::iterator i = v_agent.begin(); i != v_agent.end(); i++) {
		if ((*i)->base_hp > 0) {
			cout << m.map[(*i)->poz_x][(*i)->poz_y] << " ";
			count++;
		}
	}
	cout << endl;
	return count;
}

void Game::Play() {
	int nr=1,alive;
	string flag;
	Map m;
	vector<Item> v_item;
	vector<Agent*> v_agent;
	// initializam starea initiala si o afisam
	Setup(m, v_item, v_agent);
	cout << "Harta dupa tura 1 este:" << endl;
	m.Display();
	do {
		// asteptam comanda utilizatorului
		cout << "Doriti simularei unei alte ture? DA-1 NU-2" << endl;
		cin >> flag;
		// conversii pentru posibile date introduse
		if (flag == "DA" || flag == "Da" || flag == "da") {
			flag = "1";
		}
		if (flag == "NU" || flag == "Nu" || flag == "nu") {
			flag = "2";
		}
		if (flag == "1") {
			nr++;
			// simulam inca o tura
			alive = Turn(m, v_item, v_agent);
			// daca sunt minim doi agenti ramasi in viata
			// il intrebam din nou pe utilizator
			if (alive > 1) {
				cout << "Harta dupa tura " << nr << " este:" << endl;
				m.Display();
				m.m--;
				m.n--;
			}
			else {
				// daca un singur agent este in viata il declaram
				// castigator si inchidem sesiunea de joc
				if (alive == 1) {
					cout << "Dupa " << nr << " ture avem un castigator" << endl;
					m.Display();
				}
				else {
					// daca toti agentii sunt morti afisam un mesaj
					// corespunzator si inchidem sesiunea de joc
					cout << "Dupa " << nr << " ture nu exista un castigator" << endl;
					m.Display();
				}
				// pentru a inchide while-ul
				flag = "2";
			}
		}
		else if (flag != "2") {
			cout << "Comanda invalida" << endl;
			}
	} while (flag != "2");
}

