#include <bits/stdc++.h>
using namespace std;

int main(){
		int n; //number of days to add
		int d, m, a; //defines current date
		string s; //format: "dd/mm/yyyy"
		d = stoi(s.substr(0, 2));
		m = stoi(s.substr(3, 2));
		a = stoi(s.substr(6, 4));
		
		while (n > 0) {
			int toFill = 31;
			if (m == 4 || m == 6 || m == 9 || m == 11) toFill = 30;
			else if (m == 2) {
				if (a%4) toFill = 28;
				else toFill = 29;
			}

			if (n > toFill-d) {
				n -= toFill-d;
				d = 0;
				++m;
				if (m == 13) {
					m = 1;
					++a;
				}
			}
			else {
				d += n;
				n = 0;
			}
		}
		if (d < 10) cout << 0;
		cout << d << '/';
		if (m < 10) cout << 0;
		cout << m << '/';
		if (a < 1000) cout << 0;
		if (a < 100) cout << 0;
		if (a < 10) cout << 0;
		cout << a << endl;
}