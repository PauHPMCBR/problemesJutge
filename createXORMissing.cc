#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m, randNum;
	cin >> n >> m >> randNum;
	cout << n << ' ' << m << endl;
	for (ll i = n; i <= m; ++i) {
		if (i != randNum) cout << i << ' ';
	}
	cout << endl;
}