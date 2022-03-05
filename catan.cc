#include <bits/stdc++.h>
using namespace std;
vector<set<int>>v(25);

int getVal(set<int>s) {
	int x = 0;
	for (auto i : s) x += 6-abs(i-7);
	return x;
}

int main(){
	vector<vector<int>>p(5);
	int n;
	for (int i = 0; i < 3; ++i) {cin >> n; p[0].push_back(n);}
	for (int i = 0; i < 4; ++i) {cin >> n; p[1].push_back(n);}
	for (int i = 0; i < 5; ++i) {cin >> n; p[2].push_back(n);}
	for (int i = 0; i < 4; ++i) {cin >> n; p[3].push_back(n);}
	for (int i = 0; i < 3; ++i) {cin >> n; p[4].push_back(n);}

	for (int i = 0; i < 5; ++i) {
		v[i].insert(p[0][i/2]);
		v[i].insert(p[1][(i+1)/2]);
		if (i%2) v[i].insert(p[0][i/2+1]);
		else v[i].insert(p[1][(i+1)/2+1]);
	}
	for (int i = 0; i < 7; ++i) {
		v[i+5].insert(p[1][i/2]);
		v[i+5].insert(p[2][(i+1)/2]);
		if (i%2) v[i+5].insert(p[1][i/2+1]);
		else v[i+5].insert(p[2][(i+1)/2+1]);
	}
	for (int i = 0; i < 7; ++i) {
		v[i+12].insert(p[2][(i+1)/2]);
		v[i+12].insert(p[3][i/2]);
		if (i%2 == 0) v[i+12].insert(p[2][(i+1)/2+1]);
		else v[i+12].insert(p[3][i/2+1]);
	}
	for (int i = 0; i < 5; ++i) {
		v[i+19].insert(p[3][(i+1)/2]);
		v[i+19].insert(p[4][i/2]);
		if (i%2 == 0) v[i+19].insert(p[3][(i+1)/2+1]);
		else v[i+19].insert(p[4][i/2+1]);
	}

	int maxVal = 0;
	vector<pair<int,int>>bestIndexes;
	for (int i = 0; i < 23; ++i) {
		for (int j = i+1; j < 24; ++j) {
			set<int>prov;
			set_union(v[i].begin(), v[i].end(), v[j].begin(), v[j].end(), inserter(prov, prov.begin()));
			int x = getVal(prov);
			if (x == maxVal) bestIndexes.push_back({i,j});
			else if (x > maxVal) {
				bestIndexes.clear();
				bestIndexes.push_back({i,j});
				maxVal = x;
			}
		}
	}
	sort(bestIndexes.begin(), bestIndexes.end());
	for (auto i : bestIndexes) cout << i.first+1 << ' ' << i.second+1 << endl;
}