#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		int res = 0;
		for (int i = a; i <= b; ++i) {
			res += i*i*i;
		} 
		cout << "suma dels cubs entre " << a << " i " << b << ": " << res << endl;
	}
}