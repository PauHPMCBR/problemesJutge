#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m = n;
	int sum = 0;
	while (m > 0) {
		sum += m%10;
		m /= 100;
	}
	cout << n << (sum%2 == 0 ? " IS COOL" : " IS NOT COOL") << endl;
}