#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ll n = 0;
    vector <int> v(10000000, 0);
    for (int i = 0; i < 100; ++i) {
        for (int j = i; j < 100; ++j) {
            ll prov = ll(pow(i, 3) + pow(j, 3));
            if (prov >= 1000000) continue;
            if (v[prov] == 1) if (prov > n) n = prov;
            ++v[prov];
        }
    }
    cout << n << endl;
    
}
