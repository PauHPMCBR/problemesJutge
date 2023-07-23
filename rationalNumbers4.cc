#include <iostream>
#include <string>
using namespace std;

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

Rational add(const Rational& r1, const Rational& r2) {
    return rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational subtract(const Rational& r1, const Rational& r2) {
    return rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational multiply(const Rational& r1, const Rational& r2) {
    return rational(r1.num * r2.num, r1.den * r2.den);
}

Rational divide(const Rational& r1, const Rational& r2) {
    return rational(r1.num * r2.den, r1.den * r2.num);
}


int main() {
    Rational r;
    cin >> r.num >> r.den;
    r = rational(r.num, r.den);
    if (r.den != 1) cout << r.num << '/' << r.den << endl;
    else cout << r.num << endl;
    string op;
    while (cin >> op) {
        Rational r2;
        cin >> r2.num >> r2.den;
        r2 = rational(r2.num, r2.den);
        if (op == "add") {
            r = add(r, r2);
        } else if (op == "substract") {
            r = subtract(r, r2);
        } else if (op == "multiply") {
            r = multiply(r, r2);
        } else if (op == "divide") {
            r = divide(r, r2);
        }
        if (r.den != 1) cout << r.num << '/' << r.den << endl;
        else cout << r.num << endl;
    }
}
