#include <bits/stdc++.h>
using namespace std;

int main(){
	int esq = 1, dre = 1e5, mig;
	while (esq != dre) {
		mig = (esq+dre)/2;
		cout << mig << endl;
		char ans;
		cin >> ans;
		if (ans == '=') return 0;
		if (ans == '<') {
			dre = mig;
		}
		else {
			esq = mig+1;
		}
	}
	cout << esq << endl;
}