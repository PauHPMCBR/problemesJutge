#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	multiset<ll>s;
	char action;
	ll n;
	while (cin >> action) {
		switch (action) {
			case 'A':
				if (s.empty()) cout << "error!" << endl;
				else cout << *s.rbegin() << endl;
				break;
			case 'S':
				cin >> n;
				s.insert(n);
				break;
			case 'R':
				if (!s.empty()) {
					s.erase(s.find(*s.rbegin()));
				}
				else cout << "error!" << endl;
				break;
			case 'I':
				cin >> n;
				if (!s.empty()) {
					ll prov = *s.rbegin();
					s.erase(s.find(*s.rbegin()));
					s.insert(prov+n);
				}
				else cout << "error!" << endl;
				break;
			case 'D':
				cin >> n;
				if (!s.empty()) {
					ll prov = *s.rbegin();
					s.erase(s.find(*s.rbegin()));
					s.insert(prov-n);
				}
				else cout << "error!" << endl;
				break;
		}
	}
}