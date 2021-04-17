#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void no() {
	cout << "NO" << endl;
}

int main(){
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n < 4) {
			if (k == 0) {
				cout << "SI" << endl;
				cout << 1;
				for (ll i = 2; i <= n; ++i) cout << ' ' << i;
				cout << endl;
			}
			else no();
		}
		else if (n == 4) {
			if (k == 0) cout << "SI" << endl << "1 2 3 4" << endl;
			else if (k == 1) cout << "SI" << endl << "1 3 2 4" << endl;
			else no();
		}
		else if (n == 5) {
			if (k == 0) cout << "SI" << endl << "1 2 3 4 5" << endl;
			else if (k == 1) cout << "SI" << endl << "1 3 2 4 5" << endl;
			else if (k == 2) cout << "SI" << endl << "1 4 2 3 5" << endl;
			else if (k == 3) cout << "SI" << endl << "1 4 2 5 3" << endl;
			else no();
		}
		else {
			ll startAt = n;
			bool dontSayAnything = false;
			if (k == 1) {
				cout << "SI" << endl << "1 3 2 4";
				startAt = 5;
			}
			else if (k == 2) {
				cout << "SI" << endl << "1 4 2 3 5";
				startAt = 6;
			}
			else if (k == 3) {
				cout << "SI" << endl << "1 5 2 4 3 6";
				startAt = 7;
			}
			else if (k == 4) {
				if (n == 6) cout << "SI" << endl << "1 3 5 2 6 4";
				else cout << "SI" << endl << "1 6 2 5 3 4 7";
				startAt = 8;
			}
			else if (k == 5) {
				cout << "SI" << endl << "1 3 5 2 4 6";
				startAt = 7;
			}
			else {
				no();
				dontSayAnything = true;
			}
			if (!dontSayAnything) {
				for (ll i = startAt; i <= n; ++i) cout << ' ' << i;
				cout << endl;
			}
		}
	}
}