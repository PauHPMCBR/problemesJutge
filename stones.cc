#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<ll>v(n);
	ll ans = 0, currentMax = 0;
	bool ch = 0;
	char prevC = s[0];
	ll i = 0;
	while (s[i] == prev) {
		cin >> v[i];
		++i;
	}
	for (; i < n; ++i) {
		cin >> v[i];
		if (s[i] != prevC) {
			ch = !ch;
			if (ch == 0) {
				//cout << i << ' ' << currentMax << endl;
				ans += currentMax;
				currentMax = 0;
			}
		}
		currentMax = max(currentMax, v[i]);
		prevC = s[i];
	}


	reverse(s.begin(), s.end());
	reverse(v.begin(), v.end());
	ll ans2 = 0;
	currentMax = 0;
	ch = 0;
	prevC = s[0];
	i = 0;
	while (s[i] == prevC) {
		++i;
	}
	for (; i < n; ++i) {
		if (s[i] != prevC) {
			ch = !ch;
			if (ch == 0) {
				//cout << i << ' ' << currentMax << endl;
				ans2 += currentMax;
				currentMax = 0;
			}
		}
		currentMax = max(currentMax, v[i]);
		prevC = s[i];
	}
	cout << max(ans, ans2) << endl;
}