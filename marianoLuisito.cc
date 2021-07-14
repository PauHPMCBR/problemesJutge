#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<char>>v;
vector<vector<int>>dp;
ll f, c;

bool isValid(ll x, ll y) {
	if (x < 0 || x >= f) return false;
	if (y < 0 || y >= c) return false;
	if (v[x][y] == '*') return false;
	return true;
}

ll pathfind(ll x, ll y) {
	if (x == f-1) {
        if (v[x][y] == '*') return -1;
        return 0;
    }
    
    if (dp[x][y] != -1) return dp[x][y];
    
	ll minim = -1, prov;
    for (int i = -1; i <= 1; ++i) {
        if (isValid(x+1, y+i)) {
            if (v[x+1][y+i] == 'T') {
                prov = pathfind(x+1, y+i);
                if (prov != -1) prov += 3+abs(i);
            }
            else {
                prov = pathfind(x+1, y+i);
                if (prov != -1) prov += abs(i);
            }
            if (prov != -1 && (minim > prov || minim == -1)) minim = prov;
        }
    }
	return dp[x][y] = minim;
}

int main(){
	ll x, y;
	cin >> c >> f;
	v = vector<vector <char>>(f, vector<char>(c));
    dp = vector<vector<int>>(f, vector<int>(c, -1));
	for (ll i = 0; i < f; ++i) {
		for (ll j = 0; j < c; ++j) {
			cin >> v[i][j];
			if (v[i][j] == 'M') {x = i; y = j;}
		}
	}
	ll res = pathfind(x, y);
	if (res == -1) cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
}

