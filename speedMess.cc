#include <bits/stdc++.h>
using namespace std;

bool mobe(pair<string,int>p1, pair<string,int>p2) {
	if (p1.second > p2.second) return false;
	if (p1.second < p2.second) return true;
	if (p1.first.compare(p2.first) == 1) return true;
	return false;
}

int main(){
	map<string,int> m;
	string s;
	int a, b;
	while (cin >> s) {
		if (s == ".") {
			vector<pair<string,int>>v;
			for (auto i : m) v.push_back(i);
			sort(v.begin(), v.end(), mobe);
			for (auto i : v) cout << i.first << ' ' << i.second << endl;
			return 0;
		}
		cin >> a >> b;
		m[s] = a/b;
	}
}