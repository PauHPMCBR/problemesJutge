#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printInBase(ll n, ll base) {
    if (base <= n) printInBase(n/base, base);
    ll result = n%base;
    if (result < 26) cout << char('a' + result);
    else if (result < 26*2) cout << char('A' + result - 26);
    else cout << char('0' + result-26*2);
}

int main(){
	ll n;
	cin >> n;
	printInBase(n, 62);
	cout << endl;
}