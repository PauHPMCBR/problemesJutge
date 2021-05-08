#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>parent;
vector<int>dist;
vector<int>range;

pair<int,int> getParent(int x){
	if (x != parent[x].first) {
		int prov = parent[x].second;
		parent[x] = getParent(parent[x].first);
		parent[x].second += prov;
	}
	return parent[x];
}

void join(int x, int y){
	int parentX = getParent(x).first;
	int parentY = getParent(y).first;
	if (parentX != parentY) {
		if (range[parentX] > range[parentY])
			swap(parentX, parentY);
		parent[parentX] = {parentY,1};
		if (range[parentX] == range[parentY]) ++range[parentX];
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	parent = vector<pair<int,int>>(n);
	for (int i = 0; i < n; ++i) parent[i] = {i,0};
	dist = vector<int>(n,1);
	range = vector<int>(n);
	while (q--) {
		int t, a, b;
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			join(a-1,b-1);
		}
		else {
			cin >> a;
			auto res = getParent(a-1);
			if (a-1 != res.first) cout << res.second << endl;
			else cout << 0 << endl;
		}
	}
}