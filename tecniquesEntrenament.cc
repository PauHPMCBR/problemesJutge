#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        int prov, maxim = -1;
        for (int i = 0; i < n; ++i) {
            cin >> prov;
            maxim = max(maxim, abs(prov));
        }
        cout << maxim/2+maxim%2 << endl;
    }
}
