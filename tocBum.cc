#include <bits/stdc++.h>
using namespace std;
int n, t, b;

int bums(int tocs) {
	if ((n-(t*tocs)) % b == 0) return (n-(t*tocs)) / b;
	return -1;
}

int main(){
	cin >> t >> b >> n;
	int tocs = (n/t);
	bool gotSol = false;
	for (int i = tocs; i >= 0; --i) {
		int mobe = bums(i);
		if (mobe != -1) {
			for (int j = 0; j < i; ++j) cout << "TOC" << endl;
			for (int j = 0; j < mobe; ++j) cout << "BUM" << endl;
			gotSol = true;
			break;
		}
	}
	if (!gotSol) cout << n << endl;
}