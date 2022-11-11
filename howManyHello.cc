#include <iostream>
using namespace std;

int main() {
	string s;
	int ans = 0;
	while (cin >> s) {
		if (s == "hello") ++ans;
	}
	cout << ans << endl;
}