#include <bits/stdc++.h>
using namespace std;

int main() {
    double n,m;
    cin >> n >> m;
    if (m >= 1) cout << "mai" << endl;
    else cout << setprecision(4) << fixed << n * (1/(1-m)) << " segons" << endl;
    
}
