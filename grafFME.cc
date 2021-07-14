#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    while(cin >> n >> m) {
        if (m < n-1) cout << "disconnected" << endl;
        else if (m > (n*(n-1))/2) cout << "you've been trolled" << endl;
        else if (m > ((n-1)*(n-2))/2) cout << "connected" << endl;
        else cout << "impossible to know" << endl;
    }
}
