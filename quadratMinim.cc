#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, a, b;
	while (cin >> n >> a >> b) {
		ll esq = 1, dre = 1e15+1, mig;
		while (esq <= dre) {
			mig = (esq+dre)/2;
			if ((mig/a >= n && mig/b != 0) || (mig/b >= n && mig/a != 0)) dre = mig-1;
			else if ((mig/a) * (mig/b) < n) esq = mig+1;
			else dre = mig-1;
		}
		cout << esq << endl;
	}
}