#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>>f(9, vector<bool>(9, false));
vector<vector<bool>>c(9, vector<bool>(9, false));
vector<vector<bool>>q(9, vector<bool>(9, false));
vector<vector<int>>v(9, vector<int>(9));
int getQuadrant(int x, int y) {return (x/3)*3 + y/3;}
bool gotSol = false;

void printSudoku() {
	//cout<<"####################################" << endl;
	cout << endl;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 8; ++j) {
			cout << v[i][j]+1 << ' ';
		}
		cout << v[i][8]+1 << endl;
	}
}

void backtrack(int x, int y) {
	if (gotSol) return;
	//printSudoku();
	if (y == 9) return backtrack(x+1, 0);
	if (x == 9) {gotSol = true; return printSudoku();}
	if (v[x][y] != -1) return backtrack(x, y+1);
	
	for (int i = 0; i < 9; ++i) {
		if (!f[x][i] && !c[y][i] && !q[getQuadrant(x,y)][i]) {
			//cout << "debuj " << i << endl;
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
	int n;
	char prov;
	cin >> n;
	cout << n << endl;
	for (int k = 0; k < n; ++k) {
		gotSol = false;
		f = vector<vector<bool>>(9, vector<bool>(9, false));
		c = vector<vector<bool>>(9, vector<bool>(9, false));
		q = vector<vector<bool>>(9, vector<bool>(9, false));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> prov;
				if (prov == '.') {
					v[i][j] = -1;
					//++missing;
				}
				else {
					v[i][j] = prov - '1';
					f[i][v[i][j]] = true;
					c[j][v[i][j]] = true;
					q[getQuadrant(i,j)][v[i][j]] = true;
				}
			}
		}
		backtrack(0,0);

		//printSudoku();
	}
}