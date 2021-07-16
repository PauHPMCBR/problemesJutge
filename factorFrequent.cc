#include <bits/stdc++.h>
using namespace std;

void factor(int n, int& f, int& q) {
    int fact = -1, freq = 0;
    for (int i = 2; i*i <= n; ++i) {
        int fprov = 0;
        while (n%i == 0) {n /= i; ++fprov;}
        if (fprov > freq) {freq = fprov; fact = i;}
    }
    if (freq == 0) {freq = 1; fact = n;}
    f = fact;
    q = freq;
}
