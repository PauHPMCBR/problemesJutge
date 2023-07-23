#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x%2 == 0) return false;
	for (int i = 3; i*i <= x; i += 2) {
		if (x%i == 0) return false;
	}
	return true;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];

		bool found = false;
		for (int i = 1; i < n and not found; ++i) {
			for (int j = 0; j < i; ++j) {
				if (is_prime(v[i]+v[j])) found = true;
			}
		}
		cout << (found ? "yes" : "no") << endl;
	}
}