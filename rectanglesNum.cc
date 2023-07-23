#include <iostream>
using namespace std;

int main() {
	int n, m;
	bool first = true;
	while (cin >> n >> m) {
		if (first) first = false;
		else cout << endl;

		int num = 9;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << num;
				--num;
				if (num < 0) num = 9;
			}
			cout << endl;
		}
	}
}