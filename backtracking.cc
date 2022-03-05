#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>v;
vector<bool>used;

void b(int pos) {
	if (pos == n) {
		for (int i = 0; i < n; ++i) {
			cout << v[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			v[pos] = i;
			used[i] = true;
			b(pos+1);
			used[i] = false;
		}
	}
}

int main(){
	cin >> n;
	v = vector<int>(n);
	used = vector<bool>(n, false);
	b(0);
}