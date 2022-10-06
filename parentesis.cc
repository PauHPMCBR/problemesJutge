#include <iostream>
using namespace std;

vector<long> v(70, -1);

long catalan(int n) {
    if (n <= 1) return 1;
    if (v[n] != -1) return v[n];
    
    long res = 0;
    for (int i = 0; i < n; ++i) {
        res += catalan(i)*catalan(n-i-1);
    }
    v[n] = res;
    return res;
}

int main() {
    int n;
    while (cin >> n) {
        if (n%2 == 1) cout << 0 << endl;
        else {
            n /= 2;
            cout << catalan(n) << endl;
        }
    }
}
