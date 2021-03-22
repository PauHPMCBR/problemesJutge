#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int esq = 0, dre = v[n-1], mig = 0;
	while (esq != dre) {
		mig = (esq+dre)/2;
		if ((esq+dre)%2 == 1) ++mig;
		//cout << mig << endl;
		int c = 0;
		for (int i = n-1; i >= 0; --i) {
			if (v[i] / mig == 0) break;
			c += v[i] / mig;
		}
		if (c >= k) esq = mig;
		else dre = mig-1;
	}
	cout << esq << endl;
}