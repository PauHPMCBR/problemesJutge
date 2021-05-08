#include <bits/stdc++.h>
using namespace std;
int n,m;
int MOD = 1e9+7;
vector<int>v;
vector<int>dp;

int b(int pos) {
	if (pos == n) return 1;
	if (dp[pos] != -1) return dp[pos];
	int sum = 0;
	for (int i = 0; i != m && v[i]+pos <= n; ++i) {
		sum += b(pos+v[i]);
		sum %= MOD;
	}
	return dp[pos] = sum;
}



int main(){
	cin >> n >> m;
	v = vector<int>(m);
	dp = vector<int>(n, -1);
	string s;
	cin >> s;
	for (int i = 0; i < m; ++i) {
		cin >> s;
		v[i] = s.size();
	}
	sort(v.begin(), v.end());
	cout << b(0) << endl;
}