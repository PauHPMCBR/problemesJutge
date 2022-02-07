#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>st;
vector<ll>st2;

void add(ll p, ll tl, ll tr, ll i, ll v, bool b) {
    if (tl == tr) {
        if (b) st[p] = v;
        else st2[p] = v;
        return;
    }
    ll m = (tl+tr)/2;
    if (i <= m) add(2*p, tl, m, i, v, b);
    else add(2*p+1, m+1, tr, i, v, b);
    if (b) st[p] = st[2*p] + st[2*p+1];
    else st2[p] = st2[2*p] + st2[2*p+1];
}

ll get(ll p, ll tl, ll tr, ll l, ll r, bool b) {
    if (r < l) return 0;
    if (tl == l && tr == r) {
        if (b) return st[p];
        return st2[p];
    }
    ll m = (tl+tr)/2;
    return get(2*p, tl, m, l, min(m,r), b) + get(2*p+1, m+1, tr, max(m+1, l), r, b);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    st = vector<ll>(4*n, 0);
    st2 = vector<ll>(4*n, 0);
    for (ll i = 1; i <= n; ++i) {
        ll prov;
        cin >> prov;
        add(1, 0, n, i, prov, i%2);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll p,x;
            cin >> p >> x;
            add(1, 0, n, p, x, p%2);
        }
        else {
            ll l,r;
            cin >> l >> r;
            cout << get(1, 0, n, l, r, l%2) - get(1, 0, n, l, r, !(l%2)) << endl;
        }
    }
}
