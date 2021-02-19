#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	int counter = 0;
	while (cin >> a >> b) {
		++counter;
		cout << '#' << counter << " : ";
		double x = double(a)/double(b);
		if (a/b == x) cout << a << endl;
		else cout << int((floor(x)+1)*b) << endl;
	}
}