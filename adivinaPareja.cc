#include <bits/stdc++.h>
using namespace std;

bool ask(vector<int>v) {
	cout << '?';
	for (auto i : v) cout << ' ' << i;
	cout << endl;
	char ans; cin >> ans;
	return ans == 'm';
}

bool gaming(int n, int dif) {
	vector<int>v(n);
	int x = 1, prov = 0;
	for (int i = 0; i < n; ++i) {
		v[i] = x+1;
		++prov;
		if (prov == dif) {
			x = (x+1)%2;
			prov = 0;
		}
	}
	return ask(v);
}

bool unAltre(int n, int start) {
	vector<int>v(n,1);
	for (int i = start; i < n; ++i) v[i] = 2;
	return ask(v);
}

int main(){
	int n;
	cin >> n;
	vector<int>difs(n, 1);
	int n2 = n, dif = 1;
	while (n2 > 0) {
		if (dif >= n) break;
		bool b = gaming(n, dif);
		for (int i = 1; i < n; ++i) {
			if ((i % (dif*2)) / dif == b) difs[i] = 0;
		}
		dif *= 2;
		n2 /= 2;
	}


	for (int i = 1; i < n; ++i) {
		if (difs[i]) dif = i;
	}

	int esq = 1, dre = n-dif, mid;
	while (esq <= dre) {
		mid = (esq+dre)/2;
		if (unAltre(n, mid)) {
			esq = mid+1;
		}
		else dre = mid-1;
	}
	cout << "! " << esq << ' ' << esq+dif << endl;
}