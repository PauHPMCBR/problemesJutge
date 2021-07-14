#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x, y;
  cin >> a >> b >> y >> x;
  if ((a + x) > (b + y)) cout << "X" << endl;
  else if ((a + x) < (b + y)) cout << "Y" << endl;
  else if (x > b) cout << "X" << endl;
  else if (x < b) cout << "Y" << endl;
  else cout << "P" << endl;
}
