#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int res = 1;
	string s2;
	int streak = 1;
	while (cin >> s2) {
		if (s2 != s) streak = 0;
		else {
			++streak;
			if (streak > res) res = streak;
		}
	}
	cout << res << endl;
}