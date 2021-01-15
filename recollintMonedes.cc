#include <bits/stdc++.h>
using namespace std;

vector <vector <char> > v;
vector <vector <bool> > k;
vector <vector <bool> > b;
int n, m, money;

bool isAccessible(int x, int y, bool isHorse) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (v[x][y] == 'T') return false;
	if (isHorse) if (k[x][y]) {
		k[x][y] = false;
		money += int(v[x][y] - '0');
		v[x][y] = '0';
		return true;
	}
	if (b[x][y]) {
		b[x][y] = false;
		money += int(v[x][y] - '0');
		v[x][y] = '0';
		return true;
	}
	return false;
}

void bfs(int x, int y, bool isHorse) {
	queue <pair <int, int>> Q;
	Q.push(make_pair(x, y));
	while(!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		//cout << x << ' ' << y <<
		if (isHorse) {
			if (isAccessible(x-2, y-1, isHorse)) Q.push(make_pair(x-2, y-1));
			if (isAccessible(x+2, y-1, isHorse)) Q.push(make_pair(x+2, y-1));
			if (isAccessible(x-2, y+1, isHorse)) Q.push(make_pair(x-2, y+1));
			if (isAccessible(x+2, y+1, isHorse)) Q.push(make_pair(x+2, y+1));
			if (isAccessible(x-1, y-2, isHorse)) Q.push(make_pair(x-1, y-2));
			if (isAccessible(x-1, y+2, isHorse)) Q.push(make_pair(x-1, y+2));
			if (isAccessible(x+1, y-2, isHorse)) Q.push(make_pair(x+1, y-2));
			if (isAccessible(x+1, y+2, isHorse)) Q.push(make_pair(x+1, y+2));

		}
		else {
			if (isAccessible(x-1, y-1, isHorse)) Q.push(make_pair(x-1, y-1));
			if (isAccessible(x-1, y+1, isHorse)) Q.push(make_pair(x-1, y+1));
			if (isAccessible(x+1, y-1, isHorse)) Q.push(make_pair(x+1, y-1));
			if (isAccessible(x+1, y+1, isHorse)) Q.push(make_pair(x+1, y+1));
		}
		Q.pop();
	}
}

int main() {
	while (cin >> n >> m) {
	money = 0;
	vector<pair<int,int>> bishops;
	vector<pair<int,int>> horses;
	v = vector < vector <char> >(n, vector <char>(m));
	k = vector < vector <bool> >(n, vector <bool>(m, true));
	b = vector < vector <bool> >(n, vector <bool>(m, true));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'B') bishops.push_back(make_pair(i, j));
			else if (v[i][j] == 'K') horses.push_back(make_pair(i, j));
			if (v[i][j] == '.' || v[i][j] == 'B' || v[i][j] == 'K') v[i][j] = '0';
		}
	for (int i = 0; i < bishops.size(); ++i) bfs(bishops[i].first, bishops[i].second, false);
	for (int i = 0; i < horses.size(); ++i) bfs(horses[i].first, horses[i].second, true);
	cout << money << endl;
}
}