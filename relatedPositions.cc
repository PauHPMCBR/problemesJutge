#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sumOdd = 0;
	int sumEven = 0;
	while (n > 0) {
		sumOdd += n%10;
		n /= 10;
		sumEven += n%10;
		n /= 10;
	}
	cout << sumOdd << ' ' << sumEven << endl;
	if (sumEven == 0) cout << "0 = 0 * " << sumOdd << endl;
	else if (sumOdd == 0) cout << "0 = 0 * " << sumEven << endl;
	else if (sumEven%sumOdd == 0) {
		cout << sumEven << " = " << sumEven/sumOdd << " * " << sumOdd << endl;
	}
	else if (sumOdd%sumEven == 0) {
		cout << sumOdd << " = " << sumOdd/sumEven << " * " << sumEven << endl;
	}
	else cout << "nothing" << endl;
}