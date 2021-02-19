#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>v;

void escriu() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
        	if (v[i][j] == -2) cout << '#';
        	else if (v[i][j] == -1) cout << '.';
        	else if (v[i][j] == -3) cout << 'B';
            else cout << v[i][j];
        }
        cout << endl;
    }
}

bool isValid(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (v[x][y] == -1 || v[x][y] == -3) return true;
	return false;
}
bool mobe(int x, int y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (x > -1) return true;
	return false;
}

int main(){
	int x, y;
	cin >> n >> m;
	char prov;
	v = vector<vector<int>>(n, vector<int>(m, -2));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> prov;
			if (prov == 'A') {
				x = i;
				y = j;
				v[i][j] = 0;
			}
			else if (prov == 'B') v[i][j] = -3;
			else if (prov == '.') v[i][j] = -1;
		}
	}
	queue<pair<int,int>>q;
	q.push(make_pair(x,y));
	pair<int,int> res = make_pair(-10, -10);
	bool axuparla = true;
	while (!q.empty() && axuparla) {
		escriu();
		int i = q.front().first;
		int j = q.front().second;
		if (isValid(i+1, j)) {
			if (v[i+1][j] == -3) {
				res = make_pair(i+1, j);
				v[i+1][j] = v[i][j]+1;
				axuparla = false;
			}
			else {
				v[i+1][j] = v[i][j]+1;
				q.push(make_pair(i+1, j));
			}
		}

		if (isValid(i-1, j)) {
			if (v[i-1][j] == -3) {
				res = make_pair(i-1, j);
				v[i-1][j] = v[i][j]+1;
				axuparla = false;
			}
			else {
				v[i-1][j] = v[i][j]+1;
				q.push(make_pair(i-1, j));
			}
		}
		if (isValid(i, j+1)) {
			if (v[i][j+1] == -3) {
				res = make_pair(i, j+1);
				v[i][j+1] = v[i][j]+1;
				axuparla = false;
			}
			else {
				v[i][j+1] = v[i][j]+1;
				q.push(make_pair(i, j+1));
			}
		}
		if (isValid(i, j-1)) {
			if (v[i][j-1] == -3) {
				res = make_pair(i, j-1);
				v[i][j-1] = v[i][j]+1;
				axuparla = false;
			}
			else {
				v[i][j-1] = v[i][j]+1;
				q.push(make_pair(i, j-1));
			}
		}
		q.pop();
	}
	int i = res.first;
	int j = res.second;
	if (i == -10) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
	stack<char>output;
	cout << v[i][j] << endl;



	while (v[i][j] != 0) {
		if (mobe(i-1, j)) {if (v[i-1][j] == v[i][j]-1) {output.push('D'); i -= 1;}}
		if (mobe(i+1, j)) {if (v[i+1][j] == v[i][j]-1) {output.push('U'); i += 1;}}
		if (mobe(i, j+1)) {if (v[i][j+1] == v[i][j]-1) {output.push('L'); j += 1;}}
		if (mobe(i, j-1)) {if (v[i][j-1] == v[i][j]-1) {output.push('R'); j -= 1;}}
	}
	while (!output.empty()) {
		cout << output.top();
		output.pop();
	}
	cout << endl;
}
}