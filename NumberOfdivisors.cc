#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, t;
	cin >> t;
	while (cin >> n) {
		set<ll>s;
		ll div = 0;
		for (int i = 2; i*i <= n; ++i) {
			while (n%i == 0) {
				//if (n == i) {++div; n = 1;}
				if (!s.count(i)) {
					s.insert(i);
					div += 2;
				}
				else ++div;
				n /= i;
			}
		}
		cout << div << endl;
	}
}