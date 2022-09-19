#include <iostream>
using namespace std;

int main() {
  int a1, b1, a2, b2, a, b;
  cin >> a1 >> b1 >> a2 >> b2;
  if (a1 == a2) a = 0;
  else if (a1 > a2) a = 1;
  else a = 2;
  
  if (b1 == b2) b = 0;
  else if (b1 > b2) b = 1;
  else b = 2;
  
  if (a == 0 and b == 0) cout << "=" << endl;
  else if ((a == 1 or a == 0) and (b == 2 or b == 0)) cout << "1" << endl;
  else if ((a == 2 or a == 0) and (b == 1 or b == 0)) cout << "2" << endl;
  else cout << "?" << endl;
}