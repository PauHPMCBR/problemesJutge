#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int n, m, s;

void escriu() {
	cout << '{';
	bool firstDone = false;
	for (int i = 0; i < n; ++i) {
<<<<<<< HEAD
		for (int j = 0; j < v[i]+s; ++j) {
			if (!firstDone) firstDone = true;
			else cout << ',';
			cout << i+1;
=======
		if (v[i] != 0) {
			for (int j = 0; j < v[i]+s; ++j) {
				if (!firstDone) firstDone = true;
				else cout << ',';
				cout << i+1;
			}
>>>>>>> d9f00080e08ffba99bdbbbe8c51d55f48bfcb6c9
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
<<<<<<< HEAD
	v = vector<int>(n, 0);
	m = m-s;
=======
	m = m-s;
	v = vector<int>(n, 0);
>>>>>>> d9f00080e08ffba99bdbbbe8c51d55f48bfcb6c9
	backtrack(0);
}