#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector< vector<bool> > Board;

Board v;

bool isValid(int x, int y) {
	return (x < 10 and x >= 0 and y < 10 and y >= 0); 
}

int closest(int x, int y) {
	int k = 0;
	while (true) {
		for (int i = x-k; i <= x+k; ++i) {
			for (int j = y-k; j <= y+k; ++j) {
				if (isValid(i, j)) if (v[i][j]) return k;
			}
		}
		++k;
	}
}

int main() {
	char c;
	int n;
	v = Board(10, vector<bool>(10));

	for (int i = 0; i < 10; ++i) {
		int l;
		char dir;
		cin >> c >> n >> l >> dir;

		if (dir == 'v') for (int j = 0; j < l; ++j) v[c-'a'+j][n-1] = true;
		else for (int j = 0; j < l; ++j) v[c-'a'][n-1+j] = true;	
	}

	cout << "  12345678910" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << char('a'+i) << ' ';
		for (int j = 0; j < 10; ++j) {
			cout << (v[i][j] ? 'X' : '.');
		}
		cout << endl;
	}
	cout << endl;

	while (cin >> c >> n) {
		int dist = closest(c-'a', n-1);
		cout << c << n;
		if (dist == 0) cout << " touched!" << endl;
		else cout << " water! closest ship at distance " << dist << endl;
	}
}