#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int>v;
string s;

int getOp(int x) {
	++x;
	if (s[x] == '(') {
		int par = 1; 
		while (par != 0) {
			++x;
			if (s[x] == '(') ++par;
			else if (s[x] == ')') --par;
		}
	}
	if (s[x+1] == '+') return 0;
	if (s[x+1] == '-') return 1;
	return 2;
}

vector<vector<int>>steps;
vector<int>vals;
int applyOp() {
	int cnt = 4;
	for (auto i : steps) {
		++cnt;
		if (i[2] == 0) vals[cnt] = vals[i[0]] + vals[i[1]];
		else if (i[2] == 1) vals[cnt] = vals[i[0]] - vals[i[1]];
		else vals[cnt] = vals[i[0]] * vals[i[1]];
	}
	return vals[cnt];
}

int counter = 4;
int counter2 = -1;
int generateSteps(int x, int y) {
	if (x == y) {
		return ++counter2;
	}
	int y2 = x+1;
	if (s[y2] == '(') {
		int par = 1;
		while (par != 0) {
			++y2;
			if (s[y2] == '(') ++par;
			else if (s[y2] == ')') --par;
		}
	}

	int x2 = y-1;
	if (s[x2] == ')') {
		int par = 1;
		while (par != 0) {
			--x2;
			if (s[x2] == ')') ++par;
			else if (s[x2] == '(') --par;
		}
	}

	steps.push_back({generateSteps(x+1,y2) , generateSteps(x2, y-1) , getOp(x)});
	return ++counter;
}

bool b() {
	while (next_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; ++i) {
			vals[i] = v[i];
		}
		if (applyOp() == m) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n) {
		if (n == 0) break;
		v = vector<int>(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		cin >> m;
		cin >> s;
		steps.clear();
		vals = vector<int>(10);
		counter = 4;
		counter2 = -1;

		if (n == 1) cout << (m == v[0] ? "YES" : "NO") << endl;
		else {
			generateSteps(0,s.size()-1);
			cout << (b() ? "YES" : "NO") << endl;
		}
	}
}