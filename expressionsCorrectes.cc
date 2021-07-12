#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>>v(26, vector<int>(26, -1));

int res(int s) {
    if (s < 1 || s%2 == 0) return 0;
    if (s == 1) return v[s][m] = m;
    
    if (v[s][m] != -1) return v[s][m];
    int prov = res(s-2);
    for (int i = 0; i <= s-5; ++i) {
        prov += res(i)*res(s-5-i);
    }
    return v[s][m] = prov;
}

/*int res(int size) {
    //cout << size << endl;
    if (size == 1) return m;
    if (size < 1 || size%2 == 0) return 0;
    if (v[size] != -1) return v[size];
    int prov = 0;
    prov += res(size-2);
    for (int i = 3; i <= size/2; i+=2) {
        prov += res(size-i-1)*res(i);
    }
    return v[size] = prov;
}*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m) {
        if (!(n%2)) cout << 0 << endl;
        else if (n == 1) cout << m << endl;
        else {
            //v = vector<int>(n+1, -1);
            cout << res(n) << endl;
        }
    }
}
