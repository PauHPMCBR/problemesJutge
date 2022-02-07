#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define VI vector<int>
#define VVI vector<VI>

int n = 10;
VI available;
VI b;
VI a;
VVI v;
int sols = 0;

void print(VVI& v) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) cout << '+';
			else if (v[i][j] == 0) cout << '.';
			else cout << v[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void sol(int x, int y, bool f, int& toPut) {
	if (x == n && y == n) {
		print(v);
		++sols;
		return;
	}
	if (y == n) {
		return sol(x+1, x, !f, toPut);
	}
	if (x == n) {
		if (b[y] != a[y]) return;
		return sol(y+1, y+1, !f, toPut);
	}
	if (x == y) return sol(x, y+1, f, toPut);
	for (int i = 0; i <= toPut; ++i) {
		if (i >= available.size()) break;
		if (!available[i]) continue;
		v[x][y] = i;
		a[x] += i;
		b[y] += i;
		--available[i];
		toPut -= i;
		if (f) sol(x, y+1, f, toPut);
		else sol(x+1, y, f, toPut);
		toPut += i;
		a[x] -= i;
		b[y] -= i;
		++available[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	v = VVI(n, VI(n, 0));
	a = VI(n,0);
	b = VI(n,0);
	available = {100, 25, 13, 6, 3, 2, 1};
	//available = {100, 22, 8, 2, 1};
	//available = {100, 16, 4};
	//available = {100, 12, 2};
	int toPut = 0;
	for (int i = 1; i < available.size(); ++i) {
		toPut += available[i]*i;
		available[0] -= available[i];
	}
	available[0] -= n; //not counting diagonals
	sol(0,0,true,toPut);
}