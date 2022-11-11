#include <iostream>
using namespace std;

void f(int n) {
	if (n == 1) {
		cout << '*' << endl;
		return;
	}
	f(n-1);
	f(n-1);
	for (int i = 0; i < n; ++i) cout << '*';
	cout << endl;
}


int main() {
	int n;
	cin >> n;
	f(n);
}