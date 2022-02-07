#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>st;
vector<ll>lazy;

void apply(ll p, ll tl, ll tr, ll v) {
    lazy[p] += v;
    st[p] += (tr-tl+1)*v;
}

void push(int p, int tl, int tr) {
    if (tl != tr && lazy[p] != 0) {
        int tm = (tl+tr)/2;
        apply(2*p, tl, tm, lazy[p]);
        apply(2*p+1, tm+1, tr, lazy[p]);
    }
    lazy[p] = 0;
}

void operation(ll p, ll tl, ll tr, ll l, ll r, ll v) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(p, tl, tr, v);
        return;
    }
    push(p, tl, tr);
    ll m = (tl+tr)/2;
    operation(2*p, tl, m, l, r, v);
    operation(2*p+1, m+1, tr, l, r, v);
    st[p] = st[2*p] + st[2*p+1];
}

ll get(ll p, ll tl, ll tr, ll l, ll r) {
    if (r < l) return 0;
    if (tl == l && tr == r) return st[p];
    push(p, tl, tr);
    ll m = (tl+tr)/2;
    return get(2*p, tl, m, l, min(m,r)) + get(2*p+1, m+1, tr, max(m+1, l), r);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    st = vector<ll>(4*n, 0);
    lazy = vector<ll>(4*n, 0);
    for (ll i = 1; i <= n; ++i) {
        ll prov;
        cin >> prov;
        operation(1, 0, n, i, i, prov);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            operation(1, 0, n, l, r, x);
        }
        else {
            ll pos;
            cin >> pos;
            cout << get(1, 0, n, pos, pos) << endl;
        }
    }
}
