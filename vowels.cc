#include <bits/stdc++.h>
using namespace std;

int main(){
	set<char>vowels = {'a','e','i','o','u'};
	string s, ss;
	cin >> ss;
	s = ss;
	int changes = 0;
	for (int i = 0; i < s.size()-1; ++i) {
		if (vowels.count(s[i]) && vowels.count(s[i+1])) {
			++changes;
			char prov = s[i];
			s[i] = s[i+1];
			s[i+1] = prov;
		}
		if (s[i] != s[i+1]) changes = 30;
	}
	if (changes == 1) cout << s << endl;
	else cout << ss << endl;
}