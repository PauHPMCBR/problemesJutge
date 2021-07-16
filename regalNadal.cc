#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cas = 0;
    while (cin >> n) {
        cout << '#' << ++cas << endl;
        vector<int>v(n+1);
        v[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int prov;
            cin >> prov;
            v[i] = prov + v[i-1];
        }
        int m; 
        cin >> m;
        while (m--) {
            int a,b;
            cin >> a >> b;
            if (a > b) swap(a,b);
            cout << v[b] - v[a-1] << endl;
        }
    }
}
