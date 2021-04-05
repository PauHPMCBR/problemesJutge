#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int t;
	cin >> t;
	
	while (t--) {
		bool h=false,o=false,l=false,a=false;
		bool possible = true;
		cin >> s;
		for (auto c : s) {
			if (c == 'h') {
				if (!h) h = true;
				else possible = false;
			}
			if (c == 'o') {
				if (!o) o = true;
				else possible = false;
			}
			if (c == 'l') {
				if (!l) l = true;
				else possible = false;
			}
			if (c == 'a') {
				if (!a) a = true;
				else possible = false;
			}
		}
		if (h && o && l && a && possible) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}