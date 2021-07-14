#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector <int> w(n);
        unordered_map<int,int>m;
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
            m[w[i]] = i;
        }
        sort(w.begin(), w.end());
        vector<int>v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = m[w[i]];
        }
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            while(v[i] != i) {
                int prov = v[v[i]];
                v[v[i]] = v[i];
                v[i] = prov;
                ++swaps;
            }
        }
        cout << swaps << endl;
    }
}
