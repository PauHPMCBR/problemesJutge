#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>st;

void add(ll p, ll tl, ll tr, ll i, ll v) {
    if (tl == tr) {
        st[p] = v;
        return;
    }
    ll m = (tl+tr)/2;
    if (i <= m) add(2*p, tl, m, i, v);
    else add(2*p+1, m+1, tr, i, v);
    st[p] = max(st[2*p], st[2*p+1]);
}

ll get(ll p, ll tl, ll tr, ll k) {
    if (tl == tr) return tl;
    ll m = (tl+tr)/2;
    if (st[2*p] >= k) {
        return get(2*p, tl, m, k);
    }
    if (st[2*p+1] >= k){
        return get(2*p+1, m+1, tr, k);
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    st = vector<ll>(4*n, 0);
    for (ll i = 1; i <= n; ++i) {
        ll val;
        cin >> val;
        add(1, 0, n, i, val);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll pos, val;
            cin >> pos >> val;
            add(1, 0, n, pos, val);
        }
        else {
            ll k;
            cin >> k;
            cout << get(1, 0, n, k) << endl;
        }
    }
}
