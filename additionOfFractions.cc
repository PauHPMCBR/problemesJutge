#include <iostream>
using namespace std;

struct Fraction {
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

Fraction addition(const Fraction& x, const Fraction& y) {
  Fraction result;
  result.num = x.num * y.den + y.num * x.den;
  result.den = x.den * y.den;
  int div = gcd(result.num, result.den);
  result.num /= div;
  result.den /= div;
  return result;
}

int main() {
  Fraction result;
  char c;
  cin >> result.num >> c >> result.den;
  cin >> c;
  while (c != '=') {
    Fraction next;
    cin >> next.num >> c >> next.den;
    result = addition(result, next);
    cin >> c;
  }
  cout << result.num << '/' << result.den << endl;
}
