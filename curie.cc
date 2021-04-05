#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
<<<<<<< HEAD
set<pair<int,int>>fountains;
=======
set<pair<int,int>>fonts;
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
map<pair<int,int>,pair<int,int>>worm;
set<vector<int>>magnets;

void b(int x, int y) {
<<<<<<< HEAD
	if (v[x][y] != 0 && v[x][y] != -2 && v[x][y] != 2) return;
	if (v[x][y] == 0) v[x][y] = 1;
=======
	cout << x << ' ' << y << endl;
	if (v[x][y] != 0 && v[x][y] != -2 && v[x][y] != 2) return;

	if (v[x][y] == 0) v[x][y] = 1;

>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
	if (x < 0) return;
	if (x == n-1) return;

	//ROCKS
	if (v[x+1][y] == -1) {
<<<<<<< HEAD
=======
		//cout << "TOMA ROCA" << endl;
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
		if (y < m-1) b(x, y+1);
		if (y > 0) b(x, y-1);
		return;
	}

	//MAGNETS
	int influence = 0;
	for (auto i : magnets) {
		int x2 = i[2];
		int y2 = i[3];
		int radius = i[1];
		int power = i[0];

		if (y2 > y) power *= -1;
		if (y == y2) continue;
		int distance = 0;
		distance += (x-x2)*(x-x2);
		distance += (y-y2)*(y-y2);
		if (radius*radius > distance) influence += power;
	}
	if (influence != 0) {
		if (influence < 0) {
			if (y > 0) if (v[x+1][y+1] != -1) ++y;
		}
		else {
			if (y < m-1) if (v[x+1][y-1] != -1) --y;
		}
	}

<<<<<<< HEAD
=======
	
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
	//WORMHOLES
	if (v[x+1][y] == -2) {
		b(worm[{x+1,y}].first, worm[{x+1,y}].second);
		return;
	}

	//BLACKHOLES
	if (v[x-1][y] == -3) return;

	//NORMAL
	b(x+1, y);
<<<<<<< HEAD
=======

>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
}

int main(){
	cin >> n >> m;
	char c;
	v = vector<vector<int>>(n,vector<int>(m,0));
	while (cin >> c) {
<<<<<<< HEAD
=======
		//cout << "waiting for input" << endl;
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
		if (c == 'e') break;
		int x,y;
		cin >> x >> y;
		if (c == 'O') {
<<<<<<< HEAD
			fountains.insert({x,y});
=======
			fonts.insert({x,y});
			//v[x][y] = 1;
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
		}
		else if (c == 'R') {
			v[x][y] = -1;
		}
		else if (c == 'W') {
			int x2,y2;
			cin >> x2 >> y2;
			worm[{x,y}] = {x2,y2};
			worm[{x2,y2}] = {x,y};
			v[x][y] = -2;
			v[x2][y2] = -2;
		}
		else if (c == 'B') {
			v[x][y] = -3;
		}
		else {
			char prov;
			cin >> prov;
			int radius;
			cin >> radius;
			int power;
			cin >> power;
			if (prov == '-') power *= -1;
			magnets.insert({power,radius,x,y});
			v[x][y] = 2;
		}
<<<<<<< HEAD
	}

	for (auto i : fountains) {
		v[i.first][i.second] = 1;
		if (i.first < n-1) b(i.first+1, i.second);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == 0) cout << '.';
			if (v[i][j] == -1) cout << 'R';
			if (v[i][j] == -2) cout << 'W';
			if (v[i][j] == -3) cout << 'B';
			if (v[i][j] == 2) cout << 'M';
			if (v[i][j] == 1) cout << 'O';
		}
		cout << endl;
	}
}
=======
		

	}
	cout << "si?" << endl;
	for (auto i : fonts) {
			v[i.first][i.second] = 1;
			if (i.first < n-1)
				b(i.first+1, i.second);
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (v[i][j] == 0) cout << '.';
				if (v[i][j] == -1) cout << 'R';
				if (v[i][j] == -2) cout << 'W';
				if (v[i][j] == -3) cout << 'B';
				if (v[i][j] == 2) cout << 'M';
				if (v[i][j] == 1) cout << 'O';
			}
			cout << endl;
		}
}

/*
20
60
O 2 7
R 4 7
M 5 7 
- 4 1
R 13 5
R 13 7
R 13 9
O 4 18
R 15 17
R 16 17
R 16 18
R 16 19
R 16 20
R 16 21
R 16 22
R 16 23
R 16 24
W 16 25 4 32
R 5 32
R 10 31
M 4 38 + 7 1
B 9 38
M 10 38 + 7 1
B 15 38
M 19 29 
- 5 1
O 4 44
O 4 56
M 10 50 + 15 1
M 11 50 + 15 1
R 12 50
M 18 50 - 8 3
end

*/
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
