#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;

bool isValid(ll x, ll y) {
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	return true;
}

int main(){
	cin >> n >> m;
	vector<vector<ll>>v(n, vector<ll>(m, 0));
	v[0][0] = 1;
	priority_queue<pair<ll, pair<ll,ll>>>q;
	q.push({0,{0,0}});
	while (!q.empty()) {
		ll x = q.top().second.first;
		ll y = q.top().second.second;
		q.pop();
		if (isValid(x+2, y+1)) {
			if (v[x+2][y+1] == 0) q.push({-(x+y+3), {x+2,y+1}}); 
			v[x+2][y+1] += v[x][y];
		}
		if (isValid(x+2, y-1)) {
			if (v[x+2][y-1] == 0) q.push({-(x+y+1), {x+2,y-1}}); 
			v[x+2][y-1] += v[x][y];
		}
		if (isValid(x+1, y+2)) {
			if (v[x+1][y+2] == 0) q.push({-(x+y+3), {x+1,y+2}}); 
			v[x+1][y+2] += v[x][y];
		}
		if (isValid(x-1, y+2)) {
			if (v[x-1][y+2] == 0) q.push({-(x+y+1), {x-1,y+2}}); 
			v[x-1][y+2] += v[x][y];
		}
	}
	cout << v[n-1][m-1] << endl;
}