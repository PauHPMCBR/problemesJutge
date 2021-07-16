#include <bits/stdc++.h>
using namespace std;

vector<bool>v(1e6,1);
vector<int>primes;

void garbell() {
    for (int i = 2; i < 1e6; ++i) {
        if (v[i]) {
            primes.push_back(i);
            for (int j = i*2; j < 1e6; j+=i) {
                v[j] = 0;
            }
        }
    }
}

int main() {
    garbell();
    int n;
    while (cin >> n) {
        int divs = 1;
        for (int i = 0; i < primes.size() && primes[i]*primes[i] <= n; ++i) {
            int c = 1;
            while (n % primes[i] == 0) {
                ++c;
                n /= primes[i];
            }
            divs *= c;
        }
        if (n != 1) divs *= 2;
        cout << divs << endl;
    }
}
