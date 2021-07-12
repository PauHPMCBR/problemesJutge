#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector <char>>v;
ll f, c;

bool isValid(ll x, ll y) {
	if (x < 0 || x >= f) return false;
	if (y < 0 || y >= c) return false;
	if (v[x][y] == '*') return false;
	return true;
}

ll pathfind(ll x, ll y, ll bpress) {
	if (y == c-1) return bpress; //o/
	//v[x][y] = bpress; DYNAMIC PROGRAminimG
	ll minim = -1;
	ll prov;
	if (isValid(x-1, y+1)) {
		if (v[x-1][y+1] == 'T') prov = pathfind(x-1, y+1, bpress+4);
		else prov = pathfind(x-1, y+1, bpress+1);
		if (minim > prov || minim == -1) minim = prov;
	}
	if (isValid(x, y+1)) {
		if (v[x][y+1] == 'T') prov = pathfind(x, y+1, bpress+3);
		else prov = pathfind(x, y+1, bpress);
		if (minim > prov || minim == -1) minim = prov;
	}
	if (isValid(x+1, y+1)) {
		if (v[x+1][y+1] == 'T') prov = pathfind(x+1, y+1, bpress+4);
		else prov = pathfind(x+1, y+1, bpress+1);
		if (minim > prov || minim == -1) minim = prov;
	}
	return minim;
}

int main(){
	ll x, y;
	cin >> c >> f;
	v = vector<vector <char>>(f, vector<char>(c));
	for (ll i = 0; i < f; ++i) {
		for (ll j = 0; j < c; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'M') {x = i; y = j;}
		}
	}
	ll res = pathfind(x, y, 0);
	if (res == -1) cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
}