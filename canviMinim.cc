#include <bits/stdc++.h>
using namespace std;

vector<int>v = {200, 100, 50, 20, 10, 5, 2, 1};

int main(){
	int n;
	while (cin >> n) {
		int sum = 0, prov;
		for (int i = 0; i < n; ++i) {
			cin >> prov;
			sum += prov;
		}
		int x = 0;
		for (int i = 0; i < v.size(); ++i) {
			while (v[i] <= sum) {
				sum -= v[i];
				++x;
			}
		}
		if (x+1 >= n) cout << "si" << endl;
		else cout << "no" << endl;
	}
}