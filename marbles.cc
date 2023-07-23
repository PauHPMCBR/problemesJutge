#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>>v(101, vector<bool>(101));

void fill() {
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (!v[i][j]) {
				for (int x = 1; i+x <= 100 and j+x <= 100; ++x) {
					v[i+x][j] = 1;
					v[i][j+x] = 1;
					v[i+x][j+x] = 1;
				}
			}
			//cout << v[i][j];
		}
		//cout << endl;
	}
}


bool isD1(int l, int c) {
	if (l > 0) {
		if (!v[l-1][c]) return true;
		//if (c > 0) if (!v[l-1][c-1]) return true;
	}
	if (c > 0) if (!v[l][c-1]) return true;
	return false;
}

int main() {
	fill();
	int n;
	cin >> n;
	int d1 = 0, d2 = 0, no = 0;
	while (n--) {
		int c, l;
		cin >> l >> c;
		if (!v[l][c]) ++no; //lol
		else {
			if (isD1(l,c)) ++d1;
			else ++d2;
		}
	}
	//cout << no << ' ' <<d1 << ' ' << d2 << endl;
	if (d2 or d1%2 == 1) cout << 'Y' << endl;
	else cout << 'N' << endl;
}