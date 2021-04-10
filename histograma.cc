#include <bits/stdc++.h>
using namespace std;

bool ask(int p, int h) {
	cout << "? " << p << ' ' << h << endl;
	bool prov;
	cin >> prov;
	return prov;
}

int bs(int pos, int highest, int n) {
	vector<int>v(n, -1);
	int esq = highest+1, mig, dre = n-1;
	int lastFound = 0;
	while (dre > esq) {
		mig = (dre+esq)/2;
		if (v[mig] == -1) {
			v[mig] = ask(pos, mig);
		}
		if (v[mig]) {
			esq = mig+1;
			lastFound = mig;
		}
		else dre = mig;
	}
	if (lastFound != esq) {
		if (v[esq] == -1) {
			v[esq] = ask(pos, esq);
		}
		if (v[esq]) lastFound = esq;
	}
	return lastFound;
}

int main(){
	int n;
	cin >> n;
	int highest = 0;
	for (int i = 0; i < n; ++i) {
		highest = max(highest, bs(i, highest, n));
		if (highest == n-1) break;
	}
	cout << "! " << highest+1 << endl;
}