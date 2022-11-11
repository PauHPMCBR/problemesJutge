#include <iostream>
using namespace std;

void info_sequence(int& sum, int& last) {
	sum = 0;
	last = 0;
	int x;
	cin >> x;
	while (x != 0) {
		sum += x;
		last = x;
		cin >> x;
	}
}

int main() {
	int ans = 1;
	int sum, last;
	info_sequence(sum, last);
	int s, l;

	info_sequence(s,l);
	while (s != 0) {
		if (s == sum and l == last) ++ans;
		info_sequence(s,l);
	}
	cout << ans << endl;
}