#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<int>maxD;

int b(int x) {
    if (maxD[x] != -1) return maxD[x];
    int d = 0;
    for (auto i : v[x]) {
        d = max(d, b(i)+1);
    }
    return maxD[x] = d;
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        v = vector<vector<int>>(n);
        maxD = vector<int>(n, -1);
        while (m--) {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        int d = -1;
        for (int i = 0; i < n; ++i) {
            d = max(d, b(i));
        }
        cout << d << endl;
    }
}
