#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t,n;
vector<pair<ll,ll>>v;
vector<ll>dp;

ll highestAdv = 0;
void b(ll pos) {
    for (ll i = t; i >= 0; --i) {
        if (dp[i] == -1) continue;
        ll currentPos = i+v[pos].first;
        if (currentPos > t) continue;
        ll a = dp[i]+v[pos].second;
        if (dp[currentPos] < a) dp[currentPos] = a;
        if (a > highestAdv) highestAdv = a;
    }
}

int main() {
    while (cin >> t >> n) {
        highestAdv = 0;
        v = vector<pair<ll,ll>>(0);
        for (ll i = 0; i < n; ++i) {
            ll a,b;
            cin >> a >> b;
            if (b > a && a <= t) v.push_back({a,b-a});
        }
        dp = vector<ll>(t+1, -1);
        dp[0] = 0;
        n = v.size();
        for (ll i = 0; i < n; ++i) b(i);
        cout << t+highestAdv << endl;
    }
}
