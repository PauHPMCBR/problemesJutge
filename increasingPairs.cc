#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> b;
		if (b == 0) cout << 0 << endl;
		else {
			int cnt = 0;
			cin >> a;
			while (a != 0) {
				if (a > b) ++cnt;
				b = a;
				cin >> a;
			}
			cout << cnt << endl;
		}
	}
}