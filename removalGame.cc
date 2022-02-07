#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll>v;
vector<vector<pair<ll,ll>>>dp;

pair<ll,ll> f(int a, int b) {
	if (a == b) return {v[a], 0};
	if (dp[a][b].first != -1e9) return dp[a][b];
	auto i = f(a+1, b);
	auto j = f(a, b-1);
	i.second += v[a];
	j.second += v[b];
	if(i.second > j.second) return dp[a][b] = {i.second, i.first};
	return dp[a][b] = {j.second, j.first};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v = vector<ll>(n);
	dp = vector<vector<pair<ll,ll>>>(n, vector<pair<ll,ll>>(n, {-1e9,-1}));
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cout << f(0, n-1).first << endl;
}