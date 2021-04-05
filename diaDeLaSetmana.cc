#include <bits/stdc++.h>
using namespace std;

string dia_de_la_setmana (int d, int m, int a) {
	m -= 2;
	if (m < 1) {
		m += 12;
		--a;
	}
	int c = a/100;
	int y = a%100;
	int f = int(2.6*m - 0.2) + d + y + int(y/4) + int(c/4) - 2*c;
	while (f < 0) f += 7;
	f = f%7;
	if (f == 0) return "diumenge";
	if (f == 1) return "dilluns";
	if (f == 2) return "dimarts";
	if (f == 3) return "dimecres";
	if (f == 4) return "dijous";
	if (f == 5) return "divendres";
	return "dissabte";

}

int main() {
	int d, m, a;
	cin >> d >> m >> a;
	cout << dia_de_la_setmana(d, m, a) << endl;
}