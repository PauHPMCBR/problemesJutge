#include <bits/stdc++.h>
using namespace std;

void b(string s, int pos, string s2) {
	if (pos == s.size()) {cout << s2 << endl; return;}
	if (s[pos] == '0') return;
	if (pos == s.size()-1) return b(s, pos+1, s2 + char(s[pos]-'1'+'A'));
	b(s, pos+1, s2 + char(s[pos]-'1'+'A'));
	int n = (s[pos]-'0')*10 + s[pos+1]-'0';
	if (n <= 26) b(s, pos+2, s2 + char(n+'A'-1));
}

int main(){
	string s;
	while (cin >> s) {
		b(s, 0, "");
		cout << "----------" << endl;
	}
}