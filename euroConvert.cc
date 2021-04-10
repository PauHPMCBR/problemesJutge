#include <bits/stdc++.h>
using namespace std;

int main(){
	cout.precision(2);
	int n;
	cin >> n;
	map<string, double>m;
	double a;
	string b;
	m["EUR"] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		m[b] = a;
	}
	while (cin >> b) {
		if (b == ".") return 0;
		double amount = stod(b);
		string p, o;
		cin >> p >> o;
		cin >> o;
		cout <<	fixed << amount << ' ' << p << " = " << fixed << (amount/m[p]*m[o]) << ' ' << o << endl;
	}
}