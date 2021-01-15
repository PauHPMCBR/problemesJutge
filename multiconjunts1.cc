#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int n, m, s;

void escriu() {
	cout << '{';
	bool firstDone = false;
	for (int i = 0; i < n; ++i) {
		if (v[i] != 0) {
			for (int j = 0; j < v[i]+s; ++j) {
				if (!firstDone) firstDone = true;
				else cout << ',';
				cout << i+1;
			}
		}
	}
	cout << '}' << endl;
}

void backtrack(int pos) {
	if (pos == n) return escriu();
	for (int i = 0; i < m+1; ++i) {
		v[pos] = i;
		backtrack(pos+1);
	}
}


int main(){
	cin >> n >> s >> m;
	m = m-s;
	v = vector<int>(n, 0);
	backtrack(0);
}