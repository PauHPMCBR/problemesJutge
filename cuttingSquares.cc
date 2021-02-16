#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;

int s(int n, int m) {
	if (n == m) return 0;
	if (n == 0 || m == 0) return 0;
	if (v[n][m] != -1) return v[n][m];
	
	if (m > n) {
		m += n;
		n = m-n;
		m -= n;
	}
	int x = (s(n-1, m) + s(1, m));
	for (int i = 2; i < n/2+1; ++i) {
		x = min(x, (s(n-i, m) + s(i, m)));
	}
	for (int i = 2; i < m/2+1; ++i) {
		x = min(x, (s(n, m-i) + s(n, i)));
	}
	return v[n][m] = x+1;
}


int main(){
	int n, m;
	cin >> n >> m;
	if (m > n) {
		m += n;
		n = m-n;
		m -= n;
	}
	v = vector<vector<int>>(n+1, vector<int>(m+1, -1));
	cout << s(n, m) << endl;
}