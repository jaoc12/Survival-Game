#include "pch.h"
#include "Source.h"

//functie de afisare explicatii despre aplicatie
void Help() {
	string flag;
	do {
		cout << "Despre ce doriti mai multe informatii?" << endl
			<< "1.Harta" << endl << "2.Iteme" << endl << "3.Agenti" << endl
			<< "4.Lupta intre agenti" << endl << "5.Inapoi la meniul principal" << endl;
		cin >> flag;
		if (flag == "1") {
			cout << "Harta este de dimensiune variabila, o pozitie goala este exprimata prin --"
				<< endl << "Un item este reprezentat ca un I urmat de nr sau de ordine"
				<< endl << "Un agent este reprezentat ca un A urmat de trei cifre, prima reprezinta"
				<< " de ce tip este si celelalte nr sau de ordine si de un plus daca are item, minus altfel"
				<< endl << "Dupa fiecare tura ultima linie si coloana este eliminata" << endl;
		}
		else {
			if (flag == "2") {
				cout << "Un item ofera un bonus de hp si damage pentru agenti, are un numar "
					<< "limitat de folosiri posibile (aceste valori sunt random)." << endl
					<< "Un item folosit complet devine inutil" << endl
					<< "De asemenea unul din 10 iteme este special, avand "
					<< "efecte diferite pentru fiecare tip de agent" << endl;
			}
			if (flag == "3") {
				cout << "Agentii sunt de trei tipuri care difera prin nivelul de hp si de damage de baza"
					<< ", de felul in care se deplaseaza si de efectele itemului special" << endl
					<< "Tipul 1 are 150 hp si 35 damage, merge doua casute in jur(nu pe diagonala) si "
					<< "itemul special ii regenereaza 35 din hp (daca este ranit)" << endl
					<< "Tipul 2 are 100 hp si 50 damage, merge doua casute pe diagonala si "
					<< "itemul special ii adauga 20 damage (daca are sub jumatate din viata)" << endl
					<< "Tipul 3 are 70 hp si 70 damage, merge precum calul de la sah si "
					<< "itemul special ii scade 10 hp pentru 10 damage(daca are peste 10 hp" << endl;
			}
			if (flag == "4") {
				cout << "Lupta se desfasoara pe ture, pana cand un agent este infrant." << endl
					<< "Prima data se aplica bonusul itemului special(daca este echipat, "
					<< "dupa care urmeaza atacurile reciproce, primul este cel ce ataca" << endl
					<< "Mai intai trebuie distusa viata oferita de item, dupa hp-ul de baza" << endl
					<< "Dupa fiecare tura itemele devin mai uzate, riscand sa devina inutile" << endl;
			}
		}
		cout << endl;
	} while (flag != "5");
}

void Start(){
	cout << "Aplicatie pornita" << endl;
	string flag;
	do {
		cout << "Meniu Principal" << endl << "1.Start sesiune noua de joc" << endl 
			<< "2.Afisare informatii suplimentare" << endl << "3.Inchidere aplicatie" << endl;
		cin >> flag;
		if (flag == "1") {
			Game g;
			g.Play();
		}
		else {
			if (flag == "2") {
				Help();
			}
			else{
				if (flag != "3") {
					cout << "Comanda invalida" << endl;
				}
			}
		}
	} while (flag != "3");
	cout << "Aplicatie oprita" << endl;
}
