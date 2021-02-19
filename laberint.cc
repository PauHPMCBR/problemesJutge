#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>>v;
stack<char>res;

int isValid(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (v[x][y] == -1) return false;
	return true;
}

/*int bfs(int x, int y) {
	queue<pair<int,int>>q;
	q.push(make_pair(x, y));
	while(!q.empty() || res == 0) {
		int i = q.front().first;
		int j = q.front().second;
		cout << i << ' ' << j << endl;
		if (isValid(i+1, j, v[i][j])) {q.push(make_pair(i+1, j));}
		if (isValid(i-1, j, v[i][j])) {q.push(make_pair(i-1, j));}
		if (isValid(i, j+1, v[i][j])) {q.push(make_pair(i, j+1));}
		if (isValid(i, j-1, v[i][j])) {q.push(make_pair(i, j-1));}
		v[i][j] = -1;
		q.pop();
	}
	return res;
}*/
bool dfs(int x, int y, int steps) {
	if (!isValid(x,y)) return false;
	cout << x << ' ' << y << endl;
	if (v[x][y] == -2) {
		cout << steps+1 << endl;
		return true;
	}
	if (dfs(x+1,y,steps+1)) {res.push('D');return true;}
	if (dfs(x-1,y,steps+1)) {res.push('U');return true;}
	if (dfs(x,y+1,steps+1)) {res.push('R');return true;}
	if (dfs(x,y-1,steps+1)) {res.push('L');return true;}

	return false;

}

int main() {
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	char prov;
	int x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> prov;
			if (prov == 'A') {
				x = i;
				y = j;
				v[i][j] = -1;
			}
			else if (prov == '#') v[i][j] = -1;
			else if (prov == 'B') v[i][j] = -2;
		}
	}
	dfs(x,y,0);
	while(!res.empty()) {
		cout << res.top();
		res.pop();
	}
	cout << endl;
}