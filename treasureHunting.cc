#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char>>v;
vector<vector<bool>>visited;

bool isValid(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (v[x][y] == '#') return false;
    if (visited[x][y]) return false;
    return true;
}

vector<pair<int,int>>huntersEncountered;
int dfs(int x, int y) {
	int total = (v[x][y] == 'T');
	if (v[x][y] == 'H') huntersEncountered.push_back({x,y});
	visited[x][y] = true;
	if (isValid(x+1, y)) total += dfs(x+1, y);
	if (isValid(x-1, y)) total += dfs(x-1, y);
	if (isValid(x, y+1)) total += dfs(x, y+1);
	if (isValid(x, y-1)) total += dfs(x, y-1);
	return total;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v = vector<vector<char>>(n, vector<char>(m));
	vector<pair<int,int>>hunters;
	unordered_map<int,int>hunters2; //first int = x*10000 + y
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'H') {
				hunters.push_back({i,j});
				hunters2[i*10000+j] = -1;
			}
		}
	}
	visited = vector<vector<bool>>(n, vector<bool>(m, 0));
	for (auto i : hunters) {
		if (hunters2[{i.first*10000 + i.second}] != -1) cout << hunters2[{i.first*10000 + i.second}] << ' ';
		else {
			huntersEncountered.clear();
			int treasures = dfs(i.first, i.second);
			for (auto i : huntersEncountered) hunters2[{i.first*10000 + i.second}] = treasures;
			cout << treasures << ' ';
		}
	}
	cout << endl;
}