#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	multiset<int> s;
	char ask;
	while (n--) {
		cin >> ask;
		if (ask == '?') {
			int a,b;
			cin >> a >> b;
			auto i = lower_bound(s.begin(), s.end(), a);
			auto j = upper_bound(s.begin(), s.end(), b);
			cout << (j-s.begin())-(i-s.begin()) << endl;
		}
		else {
			int a;
			cin >> a;
			if (ask == '+') s.insert(a);
			else {
				if (s.count(a))
					s.erase(s.find(a));
			}
		}
	}
}