#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
string s;
vector<string>v;
vector<int>dp;
int n,m;

bool equal(string p, int pos) {
	string s2 = s.substr(pos, p.size());
	return p == s2;
}

int b(int pos) {
	if (pos == n) return 1;
	if (dp[pos] != -1) return dp[pos];
	int sum = 0;
	for (auto i : v) {
		if (equal(i, pos)) {
			sum += b(pos+i.size());
			sum %= MOD;
		}
	}
	return dp[pos] = sum;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	v = vector<string>(m);
	dp = vector<int>(n, -1);
	cin >> s;
	for (int i = 0; i < m; ++i) cin >> v[i];
	cout << b(0) << endl;
}