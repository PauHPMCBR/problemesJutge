#include <bits/stdc++.h>
using namespace std;

int main(){
	ll n;
	cin >> n;
	string s;
	cin >> s;

	if (n%2) {cout << 0 << endl; return 0;}

	ll prov = 0;
	bool possible = true;
	for (char c : s) {
		if (c == '(') ++prov;
		else -- prov;
		if (prov < 0) {possible = false; break;}
	}
	if (!possible) {cout << 0 << endl; return 0;}
}