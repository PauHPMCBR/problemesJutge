#include <bits/stdc++.h>
using namespace std;

bool isNumber(char c) {
	if (c <= '9' && c >= '0') return true;
	return false;
}
int mobe(string s){
	int a = 0;
	for (int i = 0; i < s.size(); ++i) {
		a += int(s[i]-'0');
		a *= 10;
	}
	return a;
}

int main(){
	string s;
	while(getline(cin, s)) {
		if (s[0] == '#') return 0;
		if (s[0] == 'P') {
			if (s[2] == ';') cout << s << endl;
			else {
				int i = 2;
				cout << s[0] << s[1] << ' ';
				bool coma = true;
				while (s[i] != ';') {
					//cout << i << s[i] << endl;
					while (i < s.size() && !isNumber(s[i])) ++i;
					int j = 0;
					while (j+i < s.size() && isNumber(s[i+j])) ++j;
					//cout << i << ' ' << j << ' ' << s.substr(i, j+1) << endl;
					int val = mobe(s.substr(i, j-1));
					if (coma) coma = false;
					else cout << ',';
					cout << val;
					i += j;
				}
				cout << ';' << endl;
			}
		}
	}
}