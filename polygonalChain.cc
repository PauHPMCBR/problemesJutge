#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i.first << ' ' << i.second << endl;
	}
}