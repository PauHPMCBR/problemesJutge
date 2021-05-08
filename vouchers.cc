#include <bits/stdc++.h> 
using namespace std;

int main() {
	int n,V;
	cin >> n >> V;
	vector<int>p(n);
	for (int i = 0; i < n; ++i) cin >> p[i];
	vector<int>p2(V);
	for (int i = 0; i < V; ++i) cin >> p2[i];
	sort(p.begin(), p.end(), greater<int>());
	sort(p2.begin(), p2.end(), greater<int>());
	int c = 0, j = 0;
	for (int i = 0; i < n; ++i) {
		if (p2[j] >= p[i]) {
			++c; ++j;
		}
	}
	cout << c << endl;
}