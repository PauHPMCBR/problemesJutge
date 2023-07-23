#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>>w;
int maxPoints;

void searchWord(vector<vector<char>>& v, string s) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int k = 0, points = 0;
			while (j+k < m and k < s.size() and v[i][j+k] == s[k]) {
				points += w[i][j+k];
				++k;
			}
			if (k == s.size() and points > maxPoints) maxPoints = points;
			
			k = 0, points = 0;
			while (i+k < n and k < s.size() and v[i+k][j] == s[k]) {
				points += w[i+k][j];
				++k;
			}
			if (k == s.size() and points > maxPoints) maxPoints = points;
		}
	}
}


int main() {
	while (cin >> n >> m) {
		vector<vector<char>>grid(n, vector<char>(m));
		w = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				cin >> grid[i][j];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				cin >> w[i][j];

		int q;
		cin >> q;
		for (int i = 0; i < q; ++i) {
			string s;
			cin >> s;
			maxPoints = -1;
			searchWord(grid, s);
			if (maxPoints == -1) cout << "no" << endl;
			else cout << maxPoints << endl;
		}
	}
}