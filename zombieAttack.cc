#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int z = 1; ++n;
	for (int i = 1; i < 1e6; ++i) {
		int diff = ceil(double(z)*0.25);
		z += min(2*z, n-z);
		z -= diff;
		n -= diff;
		if (n <= z) {
			cout << i << " days" << endl;
			break;
		}
	}
}