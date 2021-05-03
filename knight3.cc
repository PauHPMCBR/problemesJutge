#include <bits/stdc++.h>
using namespace std;

int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int a, int b) {
	return (a >= 0 && a < 8 && b >= 0 && b < 8);
}

int main(){
	char c1, c2, c3, c4;
	cin >> c1 >> c3 >> c2 >> c4;
	int n1 = c1-'a';
	int n2 = c2-'a';
	int m1 = c3-'1';
	int m2 = c4-'1';

	queue<vector<pair<int,int>>>q;
	q.push({{n1,m1}});
	vector<vector<int>>visited(8, vector<int>(8, false));
	visited[n1][m1];
	while (!q.empty()) {
		vector<pair<int,int>>v = q.front();
		int n = v[v.size()-1].first;
		int m = v[v.size()-1].second;
		q.pop();
		if (n == n2 && m == m2) {
			for (auto i : v) cout << char('a'+i.first) << i.second+1 << endl;
			break;
		}
		for (int i = 0; i < 8; ++i) {
			if (isValid(n+x[i], m+y[i])) if (!visited[n+x[i]][m+y[i]]) {
				v.push_back({n+x[i], m+y[i]});
				visited[n+x[i]][m+y[i]] = true;
				q.push(v);
				v.pop_back();
			}
		}
	}
}