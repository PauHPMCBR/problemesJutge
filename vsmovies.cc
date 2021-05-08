#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<vector<pair<ll,ll>>>v;

ll dikjstra(ll a, ll b) {
	vector<bool>visited(m, false);
	priority_queue<vector<ll>>pq;
	pq.push({0,a,0});
	pq.push({0,b,0});
	ll lel = 0;
	while (!pq.empty()) {
		ll node = pq.top()[1];
		ll dist = pq.top()[0];
		ll toSum = pq.top()[2];
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		lel += toSum;
		for (auto i : v[node]) {
			if (!visited[i.first]) {
				pq.push({-(dist+i.second), i.first, i.second});
			}
		}
	}
	return lel;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	v = vector<vector<pair<ll,ll>>>(m);
	vector<vector<ll>>pers;
	for (ll i = 0; i < n; ++i) {
		ll a,b,c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
		pers.push_back({a,b,c});
	}
	for (auto per : pers) {
		cout << dikjstra(per[0], per[1]) + per[2] << endl;
	}
}