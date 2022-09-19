#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	int n;
	cin >> n;
	while (n--) {
		cin >> s1 >> s2;
		if (s1.size() < s2.size()) cout << "NO BRAINS" << endl;
		else if (s1.size() > s2.size()) cout << "MMM BRAINS" << endl;
		else {
			if (s1 >= s2) cout << "MMM BRAINS" << endl;
			else cout << "NO BRAINS" << endl;
		}
	}
}