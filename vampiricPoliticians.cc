#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>st; //contains max
vector<int>lazy; //contains vals + sums

void push(int p, int tl, int tr) {
	if (lazy[p] != 0) {
		st[p] += lazy[p];
		if (tl != tr) {
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
	}
	lazy[p] = 0;
}

void add(int p, int tl, int tr, int l, int r, int v) {
	if (tr < l || tl > r) return;
	if (l <= tl && tr <= r) {
		lazy[p] += v;
		push(p, tl, tr);
		return;
	}
	push(p, tl, tr);
	int m = (tl+tr)/2;
	add(2*p, tl, m, l, r, v);
	add(2*p+1, m+1, tr, l, r, v);
	st[p] = max(st[2*p], st[2*p+1]);
}

int get(int tl, int tr) { //p == 1, tot el segment tree
	//push(1, tl, tr);
	return st[1];
}


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n) {
		unordered_map<string, pair<int,int>>prov;
		unordered_map<string, pair<int,int>>m;
		unordered_set<string>present;
		set<int>points;
		for (int i = 0; i < n; ++i) {
			string s;
			int a, b;
			cin >> s >> a >> b;
			prov[s] = {a,b};
			points.insert(a);
			points.insert(b);
		}
		// for (auto i : prov) {
		// 	m[i.first] = {distance(points.begin(), points.find(i.second.first)), distance(points.begin(), points.find(i.second.second))};
		// }
		
		unordered_map<int,int>mogus;
		int k = 0;
		for (auto j : points) {
			mogus[j] = k;
			++k;
		}
		for (auto i : prov) {
			m[i.first] = {mogus[i.second.first], mogus[i.second.second]};
		}
		

		int mida = points.size()+10;
		lazy = vector<int>(4*mida, 0); //? XDD
		st = vector<int>(4*mida, 0);

		string s;
		while (cin >> s) {
			if (s == "END") {
				cout << "----------" << '\n';
				break;
			}
			if (present.count(s)) {
				add(1, 0, mida, m[s].first, m[s].second, -1);
				present.erase(s);
			}
			else {
				add(1, 0, mida, m[s].first, m[s].second, 1);
				present.insert(s);
			}
			//for (auto i : st) cout << i; cout << '\n';

			cout << get(0, mida) << '\n';
		}
	}
}