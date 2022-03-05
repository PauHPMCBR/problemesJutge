#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,n;
    while (cin >> k >> n) {
        vector<int>v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int a = 0, b = 1;
        for (int i = 1; i < k; ++i) {
            if (b == a+1 && b != n-1) ++b;
            else {
                if (b == n-1 || (a != n-2 && v[a+1]+v[a+2] < v[a]+v[b+1])) {
                    ++a;
                    b = a+1;
                }
                else ++b;
            }
        }
        cout << v[a]+v[b] << endl;
    }
}
