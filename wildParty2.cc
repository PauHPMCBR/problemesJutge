#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while (cin >> n >> m) {
        vector<int>v(26, 0);
        string s;
        cin >> s;
        for (char prov : s) {
            ++v[int(prov-'a')];
        }
        int c = 0;
        for (int i = 0; i < n-1; ++i) {
            vector<int>v2(26, 0);
            cin >> s;
            for (char prov : s) {
                ++v2[int(prov-'a')];
            }
            int buf = 0;
            bool possible = true;
            for (int j = 0; j < 26; ++j) {
                buf += (v2[j] - v[j]);
                if (buf < 0) {possible = false; break;}
            }
            if (possible) ++c;
        }
        cout << c << endl;
    }
}
