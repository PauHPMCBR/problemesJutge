#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	while (cin >> n) {
		ll res = 1;
		while (n > 3) {
			++res;
			n = n/2-1;
		}
		cout << res << endl;
	}
}