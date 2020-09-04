#include <iostream>
#include <vector>
using namespace std;

int n;
vector <string> s;
vector <int> v;

void escriu() {
  cout << '(';
  for (int i = 0; i < n-1; ++i) {
    cout << s[v[i]] << ',';
  }
  cout << s[v[n-1]] << ')' << endl;
}

void lol(int p) {
  if (p == n) return escriu();
  for (int i = 0; i < n; ++i) {
    v[p] = i;
    lol(p+1);
  }
}

int main() {
  cin >> n;
  s = vector <string>(n);
  v = vector <int>(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  lol(0);
}
