#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k, d;
    cin >> n >> k >> d;
    vector<string>v(d);
    for (int i = 0; i < d; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    if (n%k == 0) {
        cout << n << endl;
        return 0;
    }
    queue<pair<string, int>>q;
    q.push({to_string(n), n%k});
    string sol="-1";
    set<int>s;
    bool stop = false;
    while (!q.empty() && !stop) {
        string act = q.front().first; 
        int mod = q.front().second;
        q.pop();
        for(int i = 0; i < d; ++i) {
            if (!s.count((10*mod + stoi(v[i]))%k)) {
                if ((10*mod + stoi(v[i]))%k == 0){
                    sol = act + v[i];
                    stop = true;
                    break;
                }
                s.insert((10*mod + stoi(v[i])) % k);
                q.push({act+v[i], (10*mod + stoi(v[i])) % k});
            }
        }
    }
    cout << sol << endl;
}