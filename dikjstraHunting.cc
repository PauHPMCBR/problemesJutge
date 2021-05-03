#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>v;
vector<vector<vector<bool>>>visited;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool isValid(int x, int y) {
	return (x < n && x >= 0 && y < m && y >= 0 && v[x][y] <= 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(4, 0)));
	char prov;
	int x,y,a,b;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> prov;
			if (prov == 'R') {x=i; y=j;}
			else if (prov == 'T') {a=i; b=j;}
			else if (prov == '#') v[i][j] = -1;
		}
	}
	priority_queue<vector<int>>pq;
	pq.push({0,x,y,0});
	pq.push({0,x,y,1});
	pq.push({0,x,y,2});
	pq.push({0,x,y,3});
	int res = -1;
	while (!pq.empty()) {
		x = pq.top()[1];
		y = pq.top()[2];
		int dir = pq.top()[3];
		if (visited[x][y][dir]) {
			pq.pop();
			continue;
		}
		//cout << x << ' ' << y << ' ' << dir << endl;  
		v[x][y] = -pq.top()[0];
		visited[x][y][dir] = true;
		pq.pop();
		if (x == a && y == b) {
			res = v[x][y];
			break;
		}

		for (int i = 0; i < 4; ++i) {
			if (isValid(x+dx[i], y+dy[i])) {
				int dist = v[x][y]+2;
				if (v[x+dx[i]][y+dy[i]] == -1) dist += 9;
				if (i != dir) ++dist;
				pq.push({-dist, x+dx[i], y+dy[i], i});
			}
		}
	}
	cout << res << endl;
}