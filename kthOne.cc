#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>st;

void add(ll p, ll tl, ll tr, ll i) {
    if (tl == tr) {
        st[p] = !st[p];
        return;
    }
    ll m = (tl+tr)/2;
    if (i <= m) add(2*p, tl, m, i);
    else add(2*p+1, m+1, tr, i);
    st[p] = st[2*p] + st[2*p+1];
}

ll get(ll p, ll tl, ll tr, ll k) {
    if (tl == tr) return tl;
    ll m = (tl+tr)/2;
    if (k <= st[2*p]) {
        return get(2*p, tl, m, k);
    }
    else {
        k -= st[2*p];
        return get(2*p+1, m+1, tr, k);
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    st = vector<ll>(4*n, 0);
    for (ll i = 1; i <= n; ++i) {
        ll prov;
        cin >> prov;
        if (prov) add(1, 0, n, i);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll pos;
            cin >> pos;
            add(1, 0, n, pos);
        }
        else {
            ll k;
            cin >> k;
            cout << get(1, 0, n, k) << endl;
        }
    }
}
