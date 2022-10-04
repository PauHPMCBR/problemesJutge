#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int ans = 0;
	int n;
	while (cin >> n) {
		if (n%x == 0) ++ans;
	}
	cout << ans << endl;
}