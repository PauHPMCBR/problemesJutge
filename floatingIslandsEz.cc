#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;

int main() {
	int n, k;
	cin >> n >> k;
	v = vector<vector<int>>(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	if (k == 1) cout << 1 << endl;
	else if (k == 2) {
		
	}
	else if (k == 3) {
		
	}
}