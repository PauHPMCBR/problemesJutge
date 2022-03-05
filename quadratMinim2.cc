#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, a, b;
	while (cin >> n >> a >> b) {
		ll esq = 1, dre = max(a,b)*n, mig;
		while (esq <= dre) {
			mig = (esq+dre)/2;
			if (sqrtl(mig/a) * sqrtl(mig/b) < sqrtl(n)) esq = mig+1;
			else dre = mig-1;
		}
		cout << esq << endl;
	}
}