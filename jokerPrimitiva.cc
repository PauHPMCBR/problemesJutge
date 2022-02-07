#include <bits/stdc++.h>
using namespace std;

int main(){
	long long t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 == s2) cout << "GANA" << endl;
		else cout << "PIERDE" << endl;
	}	
}