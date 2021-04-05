#include <bits/stdc++.h>
using namespace std;

bool mobe(pair<string,int>p1, pair<string,int>p2) {
	if (p1.second > p2.second) return true;
	if (p1.second < p2.second) return false;
	if (p1.first.compare(p2.first) == -1) return true;
	return false;
}

int main(){
	map<string,int>m;
	int n;
	cin >> n;
	string a, b;
	int money;
	for (int i = 0; i < n ; ++i) {
		cin >> a >> b;
		cin >> money;
		m[a] += money;
		m[b] -= money;
	}
	vector<pair<string,int>>v;
	for (auto i : m) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), mobe);
	for (auto i : v) {
		//if (i.second == 0) continue;
		if (i.second <= 0) cout << i.first << " pays " << i.second*(-1) << endl;
		else cout << i.first << " receives " << i.second << endl;
	}
}