#include <bits/stdc++.h>
using namespace std;

int n,f,r;
int fav = 0, cases = 1;

void b(int pos, int val) {
    if (pos == n) {
        if (val == r) ++fav;
        return;
    }
    for (int i = 1; i <= f; ++i) b(pos+1, val+i);
}

int main() {
    cin >> n >> f >> r;
    
    for (int i = 0; i < n; ++i) cases *= f;
    
    if (n*f >= r) {
        b(0,0);
    }
    
    cout << "The probability of getting a " << r <<  " with " << n << " dice of " << f << " faces is " << setprecision(3) << fixed << double(fav)/double(cases) << endl;
}
