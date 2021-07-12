#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while (cin >> n) {
		int prov, prov2;
		cin >> prov;
		bool possible = true;
		for (int i = 1; i < n; ++i) {
			cin >> prov2;
			if (prov2 != prov) possible = false;
		}
		if (possible) cout << "no" << endl;
		else cout << "si" << endl;
	}
}