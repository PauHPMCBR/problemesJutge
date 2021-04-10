#include <bits/stdc++.h>
using namespace std;

bool ask(int p, int h) {
	cout << "? " << p << ' ' << h << endl;
	bool b;
	cin >> b;
	return b;
}

int main(){
	int n, h = 0;
	cin >> n;
	for (int p = 0; p < n && h != n; ++p) {
		while (ask(p, h) && h != n) ++h;
	}
	cout << "! " << h << endl;
}