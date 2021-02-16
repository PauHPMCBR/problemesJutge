#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

int n;
vector <vector <int>>m;
int total = 0;
int cnt = 0;
set <int> res;
vector <vector<bool>>lol;

void b(int x, int sum) {
	if (lol[x][sum]) return;
	lol[x][sum] = true;
	if (x >= cnt) {
		if (!res.count(sum)) ++total;
		res.insert(sum);
		return;
	}
	for (int i = 0; i <= m[x][1]; ++i) {
		b(x+1, sum+(m[x][0]*i));
	}
}

int main(){
	cin >> n;
	vector<int>v(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	int s = 0;
	m.push_back({v[0], 1});
	for (int i = 1; i < n; ++i) {
		if (v[i] != m[s][0]) {
			m.push_back({v[i], 1});
			++s;
		}
		else ++m[s][1];
	}
	cnt = m.size();
	lol = vector<vector<bool>>(cnt+1, vector<bool>(sum+1, false));
	b(0, 0);
	cout << total-1 << endl;
	int xits2 = 0;
	for (auto i : res) {
		if (xits2 == 0) {++xits2; continue;}
		if (xits2 == 1) {cout << i; ++xits2;}
		else cout << ' ' << i;
	}
	cout << endl;
}