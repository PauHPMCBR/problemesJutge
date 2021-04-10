#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int l = 0;
	for (int i = 0; i < n; ++i) if (s[i] == 'L') ++l;
	int r = 0;
	for (int i = 0; i < l; ++i) {
		if (s[i] == 'R') ++r;
	}
	cout << r << endl;
}