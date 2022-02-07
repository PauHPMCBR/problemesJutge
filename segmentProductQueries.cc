#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll block = 600;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll>v(n);
    vector<ll>s(n/block+1, 1);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        s[i/block] *= v[i];
        s[i/block] %= m;
    }
    ll q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll res = 1;
        --a; --b;
        while (a%block != 0 && a <= b) {
            res *= v[a];
            res %= m;
            ++a;
        }
        while (a <= b-block) {
            res *= s[a/block];
            res %= m;
            a += block;
        }
        while (a <= b) {
            res *= v[a];
            res %= m;
            ++a;
        }
        cout << res << endl;
    }
}