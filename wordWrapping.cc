#include <bits/stdc++.h>
using namespace std;

int w, c, n;
vector<int>v;
vector<vector<int>>dp;

int b(int pos, int l) {
	if (pos == n) return 0;
	if (l < 1) return b(pos+1, w);
	if (dp[pos][l] != -1) return dp[pos][l];
	if (v[pos] > l) return dp[pos][l] = b(pos+1, w) + l*(c == 2 ? l : 1);
	return dp[pos][l] = max(b(pos+1, l-v[pos]-1), b(pos+1, w) + l*(c == 2 ? l : 1));
}

int main(){
	while (cin >> w >> c >> n) {
		vector<string>s(n);
		v = vector<int>(n);
		for (int i = 0; i < n; ++i) {cin >> s[i]; v[i] = s[i].size();}
		dp = vector<vector<int>>(n, vector<int>(w, -1));
		cout << b(0, w) << endl;
	}
}