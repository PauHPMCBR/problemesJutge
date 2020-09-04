#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <string> s;
vector <bool> v;

void escriu() {
  cout << '{';
  bool posarComes = false;
  for (int i = 0; i < n; ++i) {
    if (v[i]) {
      if (posarComes) cout << ',';
      else posarComes = true;
      cout << s[i];
    }
  }
  cout << '}' << endl;
}

void lul(int r, int amount) {
  if (r == n) {
    if (amount != m) return;
    return escriu();
  }
  if (amount == m) {
    for (int i = r; i < n; ++i) v[i] = false;
    return escriu();
  }
  v[r] = false;
  lul(r+1, amount);
  v[r] = true;
  lul(r+1, amount+1);
}

int main() {
  cin >> m >> n;
  s = vector <string>(n);
  v = vector <bool>(n, false);
  for (int i = 0; i < n; ++i) cin >> s[i];
  lul(0, 0);
}
