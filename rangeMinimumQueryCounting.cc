#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>>st;

pair<ll,ll> join(pair<ll,ll> p1, pair<ll,ll> p2) {
    if (p1.first == p2.first) {
        return {p1.first, p1.second + p2.second};
    }
    if (p1.first < p2.first) return p1;
    return p2;
}

void add(ll p, ll tl, ll tr, ll i, ll v) {
    if (tl == tr) {
        st[p] = {v,1};
        return;
    }
    ll m = (tl+tr)/2;
    if (i <= m) add(2*p, tl, m, i, v);
    else add(2*p+1, m+1, tr, i, v);
    st[p] = join(st[2*p], st[2*p+1]);
}

pair<ll,ll> get(ll p, ll tl, ll tr, ll l, ll r) {
    if (r < l) return {1e11,0};
    if (tl == l && tr == r) return st[p];
    ll m = (tl+tr)/2;
    return join(get(2*p, tl, m, l, min(m,r)), get(2*p+1, m+1, tr, max(m+1, l), r));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    st = vector<pair<ll,ll>>(4*n, {1e11,0});
    for (ll i = 1; i <= n; ++i) {
        ll prov;
        cin >> prov;
        add(1, 0, n, i, prov);
    }
    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll p,x;
            cin >> p >> x;
            add(1, 0, n, p, x);
        }
        else {
            ll l,r;
            cin >> l >> r;
            auto i = get(1, 0, n, l, r);
            cout << i.first << ' ' << i.second << endl;
        }
    }
}
