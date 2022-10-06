#include <iostream>
using namespace std;

int main() {
	int n;
	int pos = 1;
	cin >> n;
	while ((n%2) != 0) {
		++pos;
		cin >> n;
	}
	cout << pos << endl;
}