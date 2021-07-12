#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int>w;
vector<bool>v;

void b(int pos, int sum) {
    if (pos == m) {
        if (sum == n) {
            bool mobe = true;
            cout << '{';
            for (int i = 0; i < m; ++i) {
                if (v[i]) {
                    if (mobe) mobe = false;
                    else cout << ',';
                    cout << w[i];
                }
            }
            cout << '}' << endl;
        }
        return;
    }
    v[pos] = true;
    b(pos+1, sum+w[pos]);
    v[pos] = false;
    b(pos+1, sum);
}

int main() {
    cin >> n >> m;
    v = vector<bool>(m);
    w = vector<int>(m);
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }
    b(0,0);
}
