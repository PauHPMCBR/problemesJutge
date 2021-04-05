#include <bits/stdc++.h>
using namespace std;

vector<int>v;
int n, m, s;

void escriu() {
	cout << '{';
	bool firstDone = false;
	for (int i = 0; i < n; ++i) {
<<<<<<< HEAD
=======
<<<<<<< HEAD
		for (int j = 0; j < v[i]+s; ++j) {
			if (!firstDone) firstDone = true;
			else cout << ',';
			cout << i+1;
=======
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
		if (v[i] != 0) {
			for (int j = 0; j < v[i]+s; ++j) {
				if (!firstDone) firstDone = true;
				else cout << ',';
				cout << i+1;
			}
<<<<<<< HEAD
=======
>>>>>>> d9f00080e08ffba99bdbbbe8c51d55f48bfcb6c9
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
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
	m = m-s;
	v = vector<int>(n, 0);
=======
<<<<<<< HEAD
	v = vector<int>(n, 0);
	m = m-s;
=======
	m = m-s;
	v = vector<int>(n, 0);
>>>>>>> d9f00080e08ffba99bdbbbe8c51d55f48bfcb6c9
>>>>>>> d5dc4b0e9abf2c7c69f326aeee2e037c6de0735c
	backtrack(0);
}