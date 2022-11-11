#include <iostream>
using namespace std;

int main() {
	int f, c;
	cin >> f >> c;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			cout << (abs(i-j)%10);
		}
		cout << endl;
	}
}