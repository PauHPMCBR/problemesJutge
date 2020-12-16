#include <bits/stdc++.h>
using namespace std;

int n, p;
vector<string>v;
vector<vector<bool>>s;

void escriu() {
	for (int i = 0; i < p; ++i) {
		cout << "subconjunt " << i+1 << ": {";
		int firstDone = false;
		for (int j = 0; j < n; ++j) {
			if (s[i][j]) {
				if (firstDone) cout << ',';
				else firstDone = true;
				cout << v[j];
			}
		}
		cout << '}' << endl;
	}
	cout << endl;
}

void backtrack(int pos) {
	if (pos == n) return escriu();
	for (int i = 0; i < p; ++i) {
		s[i][pos] = true;
		backtrack(pos+1);
		s[i][pos] = false;
	}
}


int main(){
	cin >> n;
	v = vector<string>(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	cin >> p;
	s = vector<vector<bool>>(p, vector<bool>(n, false));
	backtrack(0);
}