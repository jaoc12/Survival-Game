#include "pch.h"
#include "Source.h"

void start(){
	cout << "Aplicatie pornita" << endl;
	string flag;
	do {
		cout << "Meniu Principal" << endl << "1.Start sesiune noua de joc" << endl 
			<< "2.Iesire Aplicatie" << endl;
		cin >> flag;
		if (flag == "1") {
			Game g;
			g.Play();
		}
		else {
			if (flag != "2") {
				cout << "Comanda invalida" << endl;
			}
		}
	} while (flag != "2");
	cout << "Aplicatie oprita" << endl;
}
