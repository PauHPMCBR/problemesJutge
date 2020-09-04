#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector <bool> v(1e17, true);

bool isPrime(ll n) {
    cout << n << endl;
    if (v[n]) {
        if (v[2*n] == true) for (ll i = 2*n; i < 1e16; i += n) v[i] = false;
        return true;
    }
    return false;
    
}

int main() {
    v[1] = false;
    ll result = 1;
    for (ll k = 0; k < 1e8; ++k) {
        ll prov = pow(2, k)+1;
        if (isPrime(prov)) result *= prov;
    }
    cout << result << endl;
}
