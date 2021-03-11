#include <bits/stdc++.h>
using namespace std;

int n,m,o,maxT;
vector<vector<vector<vector<bool>>>>v;
vector<int>dest;
vector<vector<int>>lol;
bool isValid(int x, int y, int z, int t) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (z < 0 || z >= o) return false;
	if (t >= maxT) return false;
	return v[x][y][z][t];
}

bool bfs(vector<int>strt) {
	//cout << 1 << endl;
	queue<pair<vector<int>, vector<vector<int>>>>q;
	q.push({strt, {}});
	while (!q.empty()) {
		//cout << 2 << endl;
		vector<int> a = q.front().first;

		vector<vector<int>> path = q.front().second;
		path.push_back(a);
		if (a == dest) {
			lol = path;
			return true;
		}
		int x = a[0], y = a[1], z = a[2], t = a[3];
		//cout << 3 << endl;
		q.pop();
		if (isValid(x,y,z,t+1)) q.push({{x,y,z,t+1}, path});
		if (isValid(x,y,z-1,t)) q.push({{x,y,z-1,t}, path});
		if (isValid(x,y,z+1,t)) q.push({{x,y,z+1,t}, path});
		if (isValid(x,y-1,z,t)) q.push({{x,y-1,z,t}, path});
		if (isValid(x,y+1,z,t)) q.push({{x,y+1,z,t}, path});
		if (isValid(x-1,y,z,t)) q.push({{x-1,y,z,t}, path});
		if (isValid(x+1,y,z,t)) q.push({{x+1,y,z,t}, path});
		//cout << 4 << endl;
	}
	return false;
}

int main(){
	cin >> n >> m >> o >> maxT;
	v = vector<vector<vector<vector<bool>>>>(n+1, vector<vector<vector<bool>>>(m+1, vector<vector<bool>>(o+1, vector<bool>(maxT))));
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<int> strt = {a,b,c,d};
	cin >> a >> b >> c >> d;
	dest = {a,b,c,d};
	string mobe;
	while (cin >> a >> b >> c >> mobe) {
		for (int i = 0; i < maxT; ++i) {
			if (mobe[i] == '_') v[a][b][c][i] = true;
			else v[a][b][c][i] = false;
		}
	}
	if (bfs(strt)) {
		for (auto i : lol) cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << endl;
	}
	else cout << "no" << endl;

}