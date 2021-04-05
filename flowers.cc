#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--) {
		double a, b;
		cin >> a >> b;
		double mobe = a*1.9116881315655996 + b*1.22872621999026 - 7.119940111025795;
		double mobe2 = 1/(1+pow(2.718281828459045, -1*mobe));
		if (mobe2 < 0.5) cout << "The flower (" << a << ' ' << b << ") is blue" << endl;
		else cout << "The flower (" << a << ' ' << b << ") is red" << endl;
	}
}