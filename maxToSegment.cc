#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>lazy;

void apply(ll p, ll tl, ll tr, ll v) {
    lazy[p] = max(lazy[p], v);
}

void push(int p, int tl, int tr) {
    if (tl != tr && lazy[p] != 0) {
        int tm = (tl+tr)/2;
        apply(2*p, tl, tm, lazy[p]);
        apply(2*p+1, tm+1, tr, lazy[p]);
    }
    lazy[p] = 0;
}

void add(ll p, ll tl, ll tr, ll l, ll r, ll v) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(p, tl, tr, v);
        return;
    }
    push(p, tl, tr);
    ll m = (tl+tr)/2;
    add(2*p, tl, m, l, r, v);
    add(2*p+1, m+1, tr, l, r, v);
    //st[p] = st[2*p] + st[2*p+1];
}

ll get(ll p, ll tl, ll tr, ll pos) {
    if (tl == tr) return lazy[p];
    push(p, tl, tr);
    ll m = (tl+tr)/2;
    if (pos <= m) return get(2*p, tl, m, pos);
    return get(2*p+1, m+1, tr, pos);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    lazy = vector<ll>(4*n, 0);
    for (ll i = 1; i <= n; ++i) {
        ll prov;
        cin >> prov;
        add(1, 0, n, i, i, prov);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            add(1, 0, n, l, r, x);
        }
        else {
            ll pos;
            cin >> pos;
            cout << get(1, 0, n, pos) << endl;
        }
    }
}
