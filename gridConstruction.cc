#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, p, q;
vector<vector<bool>>g;

vector<bool>factr, factb;

void drawr(int n) {
	int x = 499 - 3*n; //vertical
	int y = 0; //horizontal
	while (n > 0) {
		g[x][y] = 1;
		g[x+1][y] = 1;
		g[x][y+1] = 1;
		g[x+1][y+1] = 1;

		y += 2;
		x += 1;

		--n;
	}
	while (x <= 499) {
		g[x][y] = 1;
		++x;
	}
}


void drawb(int n) {
	int y = 499 - 3*n; //horizontal
	int x = 0; //vertical
	while (n > 0) {
		g[x][y] = 0;
		g[x+1][y] = 0;
		g[x][y+1] = 0;
		g[x+1][y+1] = 0;

		y += 1;
		x += 2;

		--n;
	}
	while (y <= 499) {
		g[x][y] = 0;
		++y;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> p >> q;
		g = vector<vector<bool>>(500, vector<bool>(500)); //0 = B, 1 = R
		factr = vector<bool>(64);
		factb = vector<bool>(64);

		int exp = 1;
		int cnt = 0;
		while (p != 0) {
			//cout << exp << ' ' << p << endl;
			if (p & exp) {
				factr[cnt] = true;
				p -= exp;
			}
			exp *= 2;
			++cnt;
		}

		exp = 1;
		cnt = 0;
		while (q != 0) {
			//cout << exp << ' ' << q << endl;
			if (q & exp) {
				factb[cnt] = true;
				q -= exp;
			}
			exp *= 2;
			++cnt;
		}

		//split in 2
		for (int i = 0; i < 500; ++i) {
			for (int j = i; j < 500; ++j) {
				g[i][j] = 1;
			}
		}


		//borders
		for (int i = 0; i < 500; ++i) {
			g[0][i] = 0;
			g[i][499] = 0;
			g[i][0] = 1;
			g[499][i] = 1;
		}

		//edges
		g[0][0] = 1;
		g[499][499] = 0;
		g[1][1] = 1;
		g[1][2] = 0;
		g[2][1] = 0;
		g[2][2] = 1;
		g[1][3] = 1;

		//other edges
		if (!factr[0]) g[499][0] = 0;
		if (!factb[0]) g[0][499] = 1;


		for (int i = 1; i < 64; ++i) {
			if (!factr[i]) continue;
			drawr(i);
		}
		for (int i = 1; i < 64; ++i) {
			if (!factb[i]) continue;
			drawb(i);
		}


		cout << "500 500" << endl;
		for (int i = 0; i < 500; ++i) {
			for (int j = 0; j < 500; ++j) {
				cout << (g[i][j] ? 'R' : 'B');
			}
			cout << endl;
		}
	}
}