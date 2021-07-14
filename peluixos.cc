#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector <int> v(3*n);
		for (int i = 0; i < v.size(); ++i) cin >> v[i];
		sort(v.begin(), v.end());
		int preu = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (not (i%3 == 0)) preu += v[i];
		}
		cout << preu << endl;
	}
}
