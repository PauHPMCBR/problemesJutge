#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool mobe(pair<string,ll>p1, pair<string,ll>p2) {
	if (p1.second > p2.second) return false;
	if (p1.second < p2.second) return true;
	if (p1.first.compare(p2.first) == 1) return true;
	return false;
}

int main(){
	map<string,ll>m;
	string s;
	ll a, b;
	while(cin >> s) {
		if (s == "#") {
			vector<pair<string,ll>>v;
			for (auto i : m) v.push_back(i);
			sort(v.begin(), v.end(), mobe);
			for (auto i : v) cout << i.first << ' ' << i.second << endl;
			return 0;
		}
		else {
			cin >> a >> b;
			m[s] = b-a;
		}
	}
}