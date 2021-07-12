#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char prov;
			cin >> prov;
			if (prov == 'M') v[i][j] = 1;
			else if (prov == 'T') v[i][j] = -1;
			else if (prov == '*') v[i][j] = -2;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (v[i][j] < -1) continue;
			  
		}
	}
}