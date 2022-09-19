#include <iostream>
using namespace std;


int main() {
  int a1, b1, a2, b2;
  int maxa, minb;
  cin >> a1 >> b1 >> a2 >> b2;
  if (a1 < a2) maxa = a2;
  else maxa = a1;
  if (b1 < b2) minb = b1;
  else minb = b2;
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