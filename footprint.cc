#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	double x;
	while (cin >> s) {
		if (s == "#") return 0;
		cin >> x;
		if (s == "Ship") cout << s << ' ' << setprecision(1) << fixed << x/0.3 << ' ' << (x/0.3)*23.3 << endl;
		else if (s == "Train") cout << s << ' ' << setprecision(1) << fixed << x/0.32 << ' ' << (x/0.32)*23.1 << endl;
		else if (s == "Road") cout << s << ' ' << setprecision(1) << fixed << x/2.12 << ' ' << (x/2.12)*160.1 << endl;
		else cout << s << ' ' << setprecision(1) << fixed << x/21.01 << ' ' << (x/21.01)*1577.1 << endl;
	}
}