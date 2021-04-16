#include <bits/stdc++.h>
using namespace std;

bool ask(int n) {
	cout << "? " << n << ' ' << n+1 << endl;
	char c;
	cin >> c;
	return c == '>';
}

int main(){
	int n;
	cin >> n;
	int esq = 0, mig, dre = n-1;
	while (esq != dre) {
		mig = (esq+dre)/2;
		if (ask(mig)) esq = mig+1;
		else dre = mig;
	}
	cout << "! " << esq << endl;
}