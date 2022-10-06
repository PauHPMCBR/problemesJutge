#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ending = n%1000;
	int amount = 0;
	cout << "nombres que acaben igual que " << n << ":" << endl;
	int prov;
	while (cin >> prov) {
		if (prov%1000 == ending) {
			cout << prov << endl;
			++amount;
		}
	}
	cout << "total: " << amount << endl;
}