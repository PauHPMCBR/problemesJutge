#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll esq = 1, dre = 1e9, mig;
	while (esq <= dre) {
		mig = (esq+dre)/2;
		if (mig*(mig+1)/2 < n) esq = mig+1;
		else dre = mig-1;
	}
	if (esq*(esq+1)/2 == n or dre*(dre+1)/2 == n or (esq+1)*(esq+2) == n) cout << "True" << endl;
	else cout << "False" << endl;
}