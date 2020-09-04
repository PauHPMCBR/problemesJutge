#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <ll> VI;
typedef vector <VI> VII;
typedef vector <VII> VIII;

VIII v(26, VII(26, VI(26, -1)));

long long f(int n, int b, int c) {
    if (c < 0 || n < 0 || b < 0) return 0;
    //if (b == 0 && (n != c)) return 0;
    if (b == 0 && n == c) return 1;
    if (v[n][b][c] != -1) return v[n][b][c];
    return v[n][b][c] = f(n-1, b, c)*b + f(n-1, b-1, c) + f(n-1, b, c-1);
}


int main () {
    int n, b, c;
    while (cin >> n >> b >> c) {
        cout << f(n, b, c) << endl;
    }
}
