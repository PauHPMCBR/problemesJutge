#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= 16; ++i) {
		int res = 0;
		int m = n;
		while (m > 0) {
			m /= i;
			++res;
		}
		cout << "Base " << i << ": " << res << " cifras." << endl;
	}
}