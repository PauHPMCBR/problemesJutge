#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>>f(6, vector<bool>(6, false));
vector<vector<bool>>c(6, vector<bool>(6, false));
vector<vector<bool>>q(6, vector<bool>(6, false));
vector<vector<int>>v(6, vector<int>(6));
int getQuadrant(int x, int y) {return (x/2)*2 + y/3;}
bool gotSol = false;

void printSudoku() {
	bool spaced = true;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (spaced) spaced = false;
			else cout << ' ';
			cout << v[i][j]+1;
		}
		
	}
	cout << endl;
}

void backtrack(int x, int y) {
	//cout << x << ' ' << y << endl;
	if (gotSol) return;
	//printSudoku();
	if (y == 6) return backtrack(x+1, 0);
	if (x == 6) {
		//cout << "possible solu: " << endl;
		//printSudoku();
		vector<bool>used(6,false);
		for (int i = 0; i < 6; ++i) {
			if (!used[v[i][i]]) used[v[i][i]] = true;
			else return;
		}
		used = vector<bool>(6,false);
		for (int i = 0; i < 6; ++i) {
			if (!used[v[i][5-i]]) used[v[i][5-i]] = true;
			else return;
		}
		gotSol = true; 
		return printSudoku();
	}

	if (v[x][y] != -1) return backtrack(x, y+1);
	
	for (int i = 0; i < 6; ++i) {
		if (!f[x][i] && !c[y][i] && !q[getQuadrant(x,y)][i]) {
			f[x][i] = true;
			c[y][i] = true;
			q[getQuadrant(x,y)][i] = true;
			v[x][y] = i;
			backtrack(x,y+1);
			v[x][y] = -1;
			f[x][i] = false;
			c[y][i] = false;
			q[getQuadrant(x,y)][i] = false;
		}
	}
}



int main(){
	int prov;
	gotSol = false;
	f = vector<vector<bool>>(6, vector<bool>(6, false));
	c = vector<vector<bool>>(6, vector<bool>(6, false));
	q = vector<vector<bool>>(6, vector<bool>(6, false));
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> prov;
			if (prov == 0) {
				v[i][j] = -1;
			}
			else {
				v[i][j] = prov-1;
				f[i][v[i][j]] = true;
				c[j][v[i][j]] = true;
				q[getQuadrant(i,j)][v[i][j]] = true;
			}
			//cout << i << ' ' << j << endl;
		}
	}
	backtrack(0,0);
}