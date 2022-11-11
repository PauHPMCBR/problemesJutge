#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int maxim;
		cin >> maxim;
		for (int i = 1; i < n; ++i) {
			int prov;
			cin >> prov;
			if (prov > maxim) maxim = prov;
		}
		cout << maxim << endl;
	}
}