#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (cin >> n) {
        if (n < 3) cout << n << endl;
        else cout << 2*(n-2) << endl;
    }
}
