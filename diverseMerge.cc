#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v1;
vector<int>v2;
vector<vector<vector<int>>>dp;

bool b(int p1, int p2, int prev) {
	if (p1 == n && p2 == m) return true;
	if (dp[p1][p2][prev] != -1) return dp[p1][p2][prev];

	if (p1 != n) if (v1[p1] != prev) dp[p1][p2][v1[p1]] = b(p1+1, p2, v1[p1]);
	if (p2 != m) if (v2[p2] != prev) dp[p1][p2][v2[p2]] = b(p1, p2+1, v2[p2]);
	return false;
}

int main(){
	cin >> n >> m;
	v1 = vector<int>(n);
	v2 = vector<int>(m);
	dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(500, -1)));
	for (int i = 0; i < n; ++i) cin >> v1[i];
	for (int i = 0; i < m; ++i) cin >> v2[i];
	cout << b(0,0,-1);
}