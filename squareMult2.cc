#include <iostream>
#include <vector>
using namespace std;
#define VI vector<int>
#define VII vector<VI>

void print(VII& v);

bool check(VII& v, int& size) {
	//print(v);
	for (int i = 0; i < size; ++i) {
		int p1 = 0, p2 = 0;
		for (int j = 0; j < size; ++j) {
			p1 += v[i][j];
			p2 += v[j][i];
		}
		if (p1 != p2) return false;
	}
	return true;
}

int counter = 0;
void print(VII& v) {
	++counter;
	for (auto i : v) {
		for (auto j : i) {
			cout << j;
		}
		cout << endl;
	}
	cout << endl;
}

VII v;
VI available;
int n = 4;
void generatePattern(int x, int y, int toPut) {
	if (x == n) {
		if (check(v, n)) print(v);
		return;
	}
	if (y == n) return generatePattern(x+1, 0, toPut);
	for (int i = 0; i <= toPut; ++i) {
		if (i >= available.size()) break;
		if (!available[i]) continue;
		--available[i];
		v[x][y] = i;
		generatePattern(x,y+1,toPut-i);
		++available[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	v = VII(n, VI(n, 0));
	available = {8, 4, 2, 1, 1}; //available repetitions of n^v[i]
	generatePattern(0,0,15);
	cout << counter << endl;
}