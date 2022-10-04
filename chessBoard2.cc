#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char coin;
			cin >> coin;
			if ((i+j)%2 == 0) res += int(coin - '0');
		}
	}
	cout << res << endl;
}