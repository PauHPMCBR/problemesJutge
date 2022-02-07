#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t,n,prov;
    vector<ll>cnt(2e5+2);
    cin >> n >> t;
    for (ll i = 0; i < n; ++i) {
        cin >> prov;
        ++cnt[prov];
    }
    vector<ll>v;
    for (ll i = 0; i < 2e5+2; ++i) {
        if (cnt[i] > 2) {
            int num = (cnt[i]-1)/2;
            cnt[i] -= num*2;
            cnt[2*i] += num;
        }
        for (ll j = 0; j < cnt[i]; ++j) v.push_back(i);
    }
    bitset<int(2e5+2)>b;
    b[0] = 1;
    for (int i : v) {
        b = b | (b << i);
    }
    for (int i = 1; i <= t; ++i) cout << (b[i] ? 1 : 0) << ' ';
    cout << endl;
}
