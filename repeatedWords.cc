#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string>v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<int>rep(1e5+1);
		int times = 1;
		for (int i = 1; i < n; ++i) {
			if (v[i] != v[i-1]) {
				rep[times] += v[i-1].size();
				times = 0;
			}
			++times;
		}
		rep[times] += v[n-1].size();
		times = 0;

		for (int i = 1; i < 1e5+1; ++i) {
			if (rep[i] != 0) cout << i << " : " << rep[i] << endl;
		}
		cout << endl;
	}
}