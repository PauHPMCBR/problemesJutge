#include <iostream>
#include <algorithm>
using namespace std;

void read_rational(int& num, int& den) {
    int n, m;
    char c;
    cin >> n >> c >> m;
    num = n / __gcd(n,m);
    den = m / __gcd(n,m);
}