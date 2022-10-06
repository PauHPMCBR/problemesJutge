#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int prov;
	for (int i = 0; i < n; ++i) cin >> prov;
	cout << "At the position " << n << " there is a(n) " << prov << '.' << endl;
}