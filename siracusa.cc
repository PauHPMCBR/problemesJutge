#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
  n = (n*3)+1;
  while ((n%2) == 0) {
    n = n/2;
  }
  cout << n << endl;
}
}

