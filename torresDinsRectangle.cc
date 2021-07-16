#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m;
vector <int> pos;
vector <bool> used;

void escriu() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (pos[i] == j) cout << 'R';
			else cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}

void f(int i) {
	if (i == n) {
		escriu();
		return;
	}
	for (int j = 0; j < m; ++j) {
		if (not used[j]) {
			used[j] = true;
			pos[i] = j;
			f(i + 1);
			used[j] = false;
		}
	}
}



int main() {
	cin >> n >> m;
	pos = vector<int>(n);
	used = vector<bool>(m);
	f(0);
}

