#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<int>v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}

		int i = 0;
		bool found = false;
		while (i < n and not found) {
			if (sum == 2*v[i]) found = true;
			++i;
		}
		cout << (found ? "YES" : "NO") << endl;
	}
}