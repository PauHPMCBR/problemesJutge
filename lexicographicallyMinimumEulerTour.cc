#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,string>>>v;

string dfs(int x) {
	vector<string>sols;
	for (auto i : v[x]) {
		string a = "";
		a.append(i.second);
		a.append(dfs(i.first));
		a.append(i.second);
		sols.push_back(a);
	}
	sort(sols.begin(), sols.end());
	string sol = "";
	for (string s : sols) sol += s;
	return sol;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v = vector<vector<pair<int,string>>>(n);
	for (int i = 1; i < n; ++i) {
		int x;
		string c;
		cin >> x >> c;
		v[x-1].push_back({i, c});
	}
	cout << dfs(0) << endl;
}