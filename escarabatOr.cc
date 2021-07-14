#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char, char>cript;
	string prov;
	while (cin >> prov) {
		for (int i = 0; i < 26; ++i) {
			cript[prov[i]] = char('a'+i);
		}
		cript['_'] =  ' ';
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			string input;
			cin >> input;
			for (char c : input) cout << cript[c];
			cout << endl;
		}
		cout << endl;
	}
}
