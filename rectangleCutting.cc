#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int b(int n, int m) {
	//cout << n << ' ' << m << endl;
	if (n == 0 || m == 0) return 0;
	if (n == m) return 0;
	//if (n == 1) return m;
	//if (m == 1) return n;
	if (dp[n][m] != -1) return dp[n][m];
	int minV = 1e9;
	for (int i = 1; i <= n/2; ++i) {
		minV = min(minV, b(i, m) + b(n-i, m));
	}
	for (int i = 1; i <= m/2; ++i) {
		minV = min(minV, b(n, i) + b(n, m-i));
	}
	return dp[n][m] = minV+1;
}

int main(){
	int n, m;
	cin >> n >> m;
	dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
	cout << b(n, m) << endl;
}