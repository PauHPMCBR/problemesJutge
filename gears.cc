#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
unordered_multiset<int>s;
vector<int>a;
vector<int>v;
vector<int>path;

bool findPath(int start) {
    if (!s.count(start)) return false;
    s.erase(s.find(start));
    path[0] = start;
    for (int i = 1; i < n; ++i) {
        int diff = a[i] - a[i-1] - path[i-1];
        if (s.count(diff)) {
            s.erase(s.find(diff));
            path[i] = diff;
        }
        else {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    v = vector<int>(n);
    a = vector<int>(n);
    path = vector<int>(n);
    int maxG = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
        maxG = max(maxG, v[i]);
    }

    if (n == 1) cout << v[0] << endl;
    else {
        vector<int>difs(n);
        for (int i = 1; i < n; ++i) {
            int diff = a[i] - a[i-1];
            difs[i] = diff - difs[i-1];
        }
        int maxP = 0, maxO = 0;
        for (int i = 0; i < n; i += 2) {
            maxP = max(maxP, difs[i]);
        }
        for (int i = 1; i < n; i += 2) {
            maxO = max(maxO, difs[i]);
        }
        int start1 = maxG - maxP;
        int start2 = maxO - maxG;
        if (findPath(start1)) {
            for (auto i : path) cout << i << ' ';
            cout << endl;
        }
        else {
           
            for (int i = 1; i < n; ++i) {
                cout << start2 << ' ';
                start2 = a[i] - a[i-1] - start2;
            }
            cout << start2 << endl;
        }
    }
}