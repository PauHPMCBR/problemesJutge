#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, c;
vector <ll> a;
vector <ll> q;
//vector <ll> d;

ll b(ll pos, ll s) {
	if (s == c) return 1;
	if (s > c || pos == a.size()) return 0;
	//if (d[s] != -1) return d[s];
	ll sum = 0;
	if (s+v[pos] > c) return 0;
	for (int i = 0; s+i <= c; i+=v[pos]) sum += b(pos+1, s+i);
	return sum%(1000000007);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> c;
	vector<ll>v(n);
	for (ll i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());

	int current = -1;
	int it = -1;
	for (int i = 0; i < n; ++i) {
		if (v[i] == current) ++q[it];
		else {
			a.push_back(v[i]);
			q.push_back(1);
			++it;
			current = v[i];
		}
	}

	cout << b(0, 0) << endl;
}