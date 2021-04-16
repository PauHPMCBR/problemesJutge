#include <bits/stdc++.h>
using namespace std;
vector<set<int>>v;
vector<int>visited;
stack<int>sol;

bool dfs(int x) {
	visited[x] = 1;
	for (auto i : v[x]) {
		if (!visited[i]) {
			if (!dfs(i)) return false;
		}
		else if (visited[i] == 1) {
			return false;
		}
	}
	visited[x] = 2;
	sol.push(x);
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	v = vector<set<int>>(26);
	visited = vector<int>(26, false);
	bool possible = true;

	string prev = ".";
	while (m--) {
		string curr;
		cin >> curr;
		if (prev != ".") {
			bool done = false;
			for (int i = 0; i < curr.size() && i < prev.size(); ++i) {
				if (curr[i] != prev[i]) {
					v[prev[i]-'a'].insert(curr[i]-'a');
					done = true;
					break;
				}
			}
			if (!done) if (curr.size() < prev.size()) possible = false;
		}
		prev = curr;
	}
	
	for (int i = 0; i < 26 && possible; ++i) {
		if (!visited[i]) {
			if (!dfs(i)) possible = false;
		}
	}
	if (!possible) cout << "NO" << endl;
	else  {
		cout << "YES" << endl;
		while (!sol.empty()) {
			cout << char('a' + sol.top());
			sol.pop();
		}
		cout << endl;
	}
}