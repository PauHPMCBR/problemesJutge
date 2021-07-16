#include <bits/stdc++.h>
using namespace std;

void b(int n) {
    if (n == 0) return;
    b(n-1);
    cout << n;
    for (int i = 0; i < n-1; ++i) cout << ' ' << n;
    cout << endl;
    b(n-1);
}

int main() {
    int n;
    cin >> n;
    b(n);
}
