#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
	int res = 0;
	while (n > 0) {
		res += n%10;
		n /= 10;
	}
	return res;
}

int main() {
	vector <bool> v(1e6*4 + 1, true);

	v[0] = false;
	v[1] = false;
	for (int i = 2; i <= 1e6*4; ++i) {
		if (v[i]) for (int j = i*2; j <= 1e6*4; j+=i) v[j] = false;
	}
	int n;
	while (cin >> n) {
		if (n == 0) return 1;
		bool perfect = true;
		while(n >= 10) {
			if (!v[n]) {
				perfect = false;
				break;
			}
			//cout << n << ' ';
			n = sum(n);
		}
		if (!v[n]) {
			perfect = false;
		}
		if (perfect) cout << "yes" << endl;
		else cout << "no" << endl;
	}

}