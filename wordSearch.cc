#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>>w;

void searchWord(vector<vector<char>>& v, string s) {
	int n = v.size();
	int m = v[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] == s[0]) {
				int k = 1;
				while (j+k < m and k < s.size() and v[i][j+k] == s[k]) ++k;
				if (k == s.size()) {
					for (k = 0; k < s.size(); ++k) 
						w[i][j+k] = v[i][j+k] - 'a' + 'A';
				}
				k = 1;
				while (i+k < n and k < s.size() and v[i+k][j] == s[k]) ++k;
				if (k == s.size()) {
					for (k = 0; k < s.size(); ++k) 
						w[i+k][j] = v[i+k][j] - 'a' + 'A';
				}
				k = 1;
				while (j+k < m and i+k < n and k < s.size() and v[i+k][j+k] == s[k]) ++k;
				if (k == s.size()) {
					for (k = 0; k < s.size(); ++k) 
						w[i+k][j+k] = v[i+k][j+k] - 'a' + 'A';
				}
			}
		}
	}

}

int main() {
	int x, n, m;
	bool first = true;
	while (cin >> x >> n >> m) {
		if (first) first = false;
		else cout << endl;
		vector<string>words(x);
		for (int i = 0; i < x; ++i) cin >> words[i];
		vector<vector<char>>grid(n, vector<char>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				cin >> grid[i][j];

		w = grid;
		for (int i = 0; i < words.size(); ++i) searchWord(grid, words[i]);

		for (int i = 0; i < n; ++i) {
			cout << w[i][0];
			for (int j = 1; j < m; ++j) {
				cout << ' ' << w[i][j];
			}
			cout << endl;
		}
	}
}