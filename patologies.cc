#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string>v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int p;
        char y,x;
        cin >> p >> y;
        --p;
        x = v[0][p];
        int n1=0,n2=0;
        for (int j = 0; j < n; ++j) {
            if (v[j][p] == x) ++n1;
            if (v[j][p] == y) ++n2;
        }
        if (2*n2 >= n1) cout << "neutral" << endl;
        else cout << "patologica" << endl;
    }
}
