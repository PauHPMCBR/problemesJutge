#include <bits/stdc++.h>
using namespace std;

void recurs(int n) {
	if (n == 1) {
		cout << '*' << endl;
		return;
	}
	recurs(n-1);
	for (int i = 0; i < n; ++i) cout << '*';
	cout << endl;
	recurs(n-1);
}


int main() {
	int n;
	cin >> n;
	recurs(n);
}