#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		
		double prov;
		cin >> prov;
		double suma, minim, maxim;
		suma = minim = maxim = prov;
		for (int j = 1; j < m; ++j) {
			cin >> prov;
			if (prov < minim) minim = prov;
			if (prov > maxim) maxim = prov;
			suma += prov;
		}
		cout << minim << ' ' << maxim << ' ' << suma/m << endl;
	}
}