#include <bits/stdc++.h>
using namespace std;

bool mobe(pair<int,int>p1, pair<int,int>p2) {
	if (p1.second > p2.second) return true;
	if (p1.second < p2.second) return false;
	if (p1.first > p2.first) return false;
	return true;
}

int main(){
	map<int,int> m;
	int s;
	int a, b;
	while (cin >> s) {
		if (s == 0) {
			vector<pair<int,int>>v;
			for (auto i : m) v.push_back(i);
			sort(v.begin(), v.end(), mobe);
			for (int i = 0; i < 3; ++i) cout << v[i].first << ' ' << v[i].second << endl;
			return 0;
		}
		cin >> a >> b;
		m[s] += 3;
		m[a] += 2;
		m[b] += 1;
	}
}