#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n;
    n *= 2;
    string prov;
    cin >> prov;
    if (prov.size()%2 == 0) {cout << 'B' << endl; return 0;}
    c = prov[prov.size()/2] - '0';
    for (int i = 1; i < n; ++i) {
        cin >> prov;
        if (prov.size()%2 == 0) {cout << (i%2 == 0 ? 'B' : 'A') << endl; return 0;}
        if (prov[prov.size()/2] - '0' != c) {cout << (i%2 == 0 ? 'B' : 'A') << endl; return 0;}
    }
    cout << '=' << endl;
}
