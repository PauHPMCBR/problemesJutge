#include <bits/stdc++.h>
using namespace std;

void printInBase(int n, int base) {
    if (base <= n) printInBase(n/base, base);
    int result = n%base;
    if (result < 10 ) cout << result;
    else cout << char('A' + result-10);
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << " = ";
        printInBase(n, 2);
        cout << ", ";
        printInBase(n, 8);
        cout<< ", ";
        printInBase(n, 16);
        cout << endl;
    }
}
