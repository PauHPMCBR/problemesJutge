#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<vector<int>>v;

void floyd() {
	for (int k = 0; k < n; k++) { 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][k] + v[k][j] < v[i][j]) 
					v[i][j] = v[i][k] + v[k][j]; 
			} 
		} 
	} 
}

set<vector<int>>sols;

int mobe(int a, int b, int c, set<int>valid) {
	if (c != -1) {
		vector<int>move = {a,b,c};
		sort(move.begin(), move.end());
		if (sols.count(move)) return 0;
		sols.insert(move);
		//cout << a << ' ' << b << ' ' << c << endl;
		return 1;
	}
	int s = 0;
	if (b == -1) {
		set<int>valid2;
		for (auto i : valid) {
			if (v[a][i] > 1 && v[a][i] < 1e7) valid2.insert(i);
		}
		for (auto i : valid2) s += mobe(a, i, -1, valid2);
	}
	else {
		for (auto i : valid) {
			if (v[b][i] > 1 && v[b][i] < 1e7) s += mobe(a, b, i, valid);
		}
	}
	return s;
}

int main(){
	cin >> t;
	while (t--) {
		sols = set<vector<int>>();
		cin >> n;
		v = vector<vector<int>>(n, vector<int>(n, 2*1e7));
		int a, b;
		for (int i = 0; i < n-1; ++i) {
			v[i][i] = 0;
			cin >> a >> b;
			v[a][b] = 1;
			v[b][a] = 1;
		}
		v[n-1][n-1] = 0;
		floyd();

		int s = 0;
		for (int i = 0; i < n; ++i){
			set<int>valid;
			for (int j = 0; j < n; ++j) {
				if (v[i][j] > 1 && v[i][j] < 1e7) valid.insert(j);
			}
			s += mobe(i, -1, -1, valid);
		}
		cout << s << endl;
	}
}