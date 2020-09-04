#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector <int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            while(v[i] != i+1) {
                int prov = v[v[i]-1];
                v[v[i]-1] = v[i];
                v[i] = prov;
                ++swaps;
            }
        }
        cout << swaps << endl;
    }
}
