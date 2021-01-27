#include <bits/stdc++.h>
using namespace std;

int n;
int sum = 0;
vector <bool>v;
vector <int>m;
vector <bool>p;
int total = 0;

void b(int x, int s) {
	if (x == n) {
		if (!v[s]) ++total; 
		v[s] = true; 
		return;
	}
	b(x+1, s);
	b(x+1, s+m[x]);
}

int main(){
	cin >> n;
	m = vector<int>(n);
	p = vector<bool>(n, true);
	for (int i = 0; i < n; ++i) {
		cin >> m[i];
		sum += m[i];
	}
	v = vector<bool>(sum+1, false);
	b(0, 0);

	cout << total-1 << endl;
	int i = 1;
	while (!v[i]) ++i;
	cout << i;
	++i;
	for (; i <= sum; ++i) if (v[i]) cout << ' ' << i;
	cout << endl;
}