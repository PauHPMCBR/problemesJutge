#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) return 1;
		map<string, int>m;
		string name;
		cin >> name;
		string moda = name;
		int modaValue = 1, prov;
		m.insert(make_pair(name, 1));
		for (int i = 1; i < n; ++i) {
			cin >> name;

			if (!m.count(name)) {
				m.insert(make_pair(name, 1));
				prov = 1;
			}
			else {
				prov = m[name]+1;
				m[name] = prov;
			}
			if (prov > modaValue) {moda = name; modaValue = prov;}
			else if (prov == modaValue) if (name > moda) {moda = name; modaValue = prov;}
			//cout << prov << endl;
		}
		cout << moda << endl;
	}
}