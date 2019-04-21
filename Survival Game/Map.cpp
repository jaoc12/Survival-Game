#include "pch.h"
#include "Map.h"

Map::Map() {}

void Map::Set(int x,int y){
	m = x;
	n = y;
	map.resize(x);
	for (int i = 0; i < x; i++)
		map[i].resize(y);
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			map[i][j] = "-";
}

Map::~Map(){
	for (auto i = map.begin(); i != map.end(); i++)
		i->clear();
	map.clear();
}

void Map::Display() {
	cout << "     ";
	for (int i = 0; i < n; i++) {
		if(i<10)
			cout << "  C" << i << "  ";
		else cout << " C" << i << "  ";
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << "L" << i << "   ";
		for (int j = 0; j < n; j++) {
			if (map[i][j] == "-")
				cout << "  " << map[i][j] << "-  ";
			else {
				if (map[i][j][0] == 'A')
					cout << map[i][j] << " ";
				else cout << "  " << map[i][j] << " ";
			}
			
		}
		cout << endl;
	}
}
