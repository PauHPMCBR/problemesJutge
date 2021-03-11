#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>v(n+1, 0);
	for (int i = 1; i < min(7, n+1); ++i) v[i] = 1;
	for (int i = 0; i < n+1; ++i) {
		for (int j = 1; j < 7; ++j) {
			if (i+j >= n+1) break;
			v[i+j] += v[i];
			v[i+j] %= 1000000007;
		}
	}
	cout << v[n] << endl;
}