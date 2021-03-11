#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
		for (int i = a; i <= b; ++i) {
			for (int j = c; j <= d; ++j) {
				double res = sqrt(i*i+j*j);
				if (res - floor(res) == 0) {
					cout << i << "^2 + " << j << "^2 = " << res << "^2" << endl;
					return 0;
				}
			}
		}
	cout << "Sense solucio!" << endl;

}