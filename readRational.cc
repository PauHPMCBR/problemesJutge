#include <bits/stdc++.h>
using namespace std;

bool read_rational(int& num, int& den) {
    int n,m;
    char c;
    while (cin >> n >> c >> m) {
    if (m == 0) return false;
    num = n / __gcd(n,m);
    den = m / __gcd(n,m);
    return true;
}
return false;
}
