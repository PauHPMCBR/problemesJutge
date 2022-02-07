#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int d, m, a, n;
	while (getline(cin, s)) {
		if (s == "00/00/0000 0 0 0") return 0;
		int currentPos = 11;
		int inc = 1;
		while (s[currentPos+inc] != ' ') ++inc;
		a = stoi(s.substr(currentPos, inc));
		currentPos += inc+1;
		inc = 1;
		
		while (s[currentPos+inc] != ' ') ++inc;
		m = stoi(s.substr(currentPos, inc));
		currentPos += inc+1;
		inc = 1;
		
		d = stoi(s.substr(currentPos, s.size()-currentPos));
		//cout << a << '_' << m << '_' << d << '_' << endl;

		m += a*12;
		n = d + m*28;
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
	
}