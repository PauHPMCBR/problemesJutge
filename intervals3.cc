#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  int a1, b1, a2, b2, a, b;
  int maxa, minb;
  cin >> a1 >> b1 >> a2 >> b2;

  if (a1 == a2) a = 0;
  else if (a1 > a2) a = 1;
  else a = 2;
  if (b1 == b2) b = 0;
  else if (b1 > b2) b = 1;
  else b = 2;
  
  if (a1 < a2) maxa = a2;
  else maxa = a1;
  if (b1 < b2) minb = b1;
  else minb = b2;
  
  if (a == 0 and b == 0) cout << "=";
  else if ((a == 1 or a == 0) and (b == 2 or b == 0)) cout << "1";
  else if ((a == 2 or a == 0) and (b == 1 or b == 0)) cout << "2";
  else cout << "?";
  
  cout << " , ";
  
  if (maxa > minb) cout << "[]" << endl;
  else {
    cout << "[";
    if (a1 < a2) cout << a2;
    else cout << a1;
    cout << ",";
    if (b1 > b2) cout << b2;
    else cout << b1;
    cout << "]" << endl;
  }
}