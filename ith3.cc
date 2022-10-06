#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int prov, sol;
	int pos = 0;
	while (cin >> prov) {
		if (pos == n-1) sol = prov;
		++pos;
	}
	if (pos >= n and n > 0) cout << "At the position " << n << " there is a(n) " << sol << '.' << endl;
	else cout << "Incorrect position." << endl;
}