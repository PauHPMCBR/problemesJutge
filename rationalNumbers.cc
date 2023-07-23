#include <algorithm>

struct Rational {
    int num, den;
};

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

Rational rational(int n, int d) {
    int g = gcd(n, d);
    n /= g;
    d /= g;
    if (n == 0) {
        d = 1;
    } else if (d < 0) {
        n = -n;
        d = -d;
    }
    return {n, d};
}
