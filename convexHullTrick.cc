#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<double,double>>v;

double intersec(int a,int b){
	if(v[a].first == v[b].first)return INT_MAX;
	return (1.0*v[b].second - v[a].second)/(v[a].first - v[b].first);
}

signed main() {
	int n;
	cin >> n;
	v = vector<pair<double,double>>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<double>X;
	vector<int>lines;
	X.push_back(intersec(0, 1));
	lines.push_back(0);
	lines.push_back(1);

	for (int i = 2; i < n; ++i) {
		int last = X.size()-1;
		double prov = intersec(i, last+1);
		while (lines.size() > 1 && prov < X[last]) {
			X.pop_back();
			lines.pop_back();
			--last;
			prov = intersec(i, last+1);
		}
		X.push_back(prov);
		lines.push_back(i);
	}
	for (auto i : lines) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}
