#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	multiset<int> s;
	char ask;
	int a;
	while (cin >> ask) {
		if (ask == 'N') {
			if (s.empty()) cout << "error: magatzem buit" << endl;
			else cout << *s.begin() << endl;
		}
		else if (ask == 'X') {
			if (s.empty()) cout << "error: magatzem buit" << endl;
			else {
				auto it = s.end();
				--it;
				cout << *it << endl;
			}
		}
		else if (ask == 'A') {
			cin >> a;
			s.insert(a);
		}
		else {
			cin >> a;
			if (s.find(a) == s.end()) cout << "error: preu inexistent (" << a << ')' << endl;
			else s.erase(s.find(a));
		}
	}
}