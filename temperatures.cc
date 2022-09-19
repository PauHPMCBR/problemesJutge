#include <iostream>
using namespace std;

const int HOT = 30;
const int COLD = 10;
const int BOIL = 100;
const int FREEZE = 0;

int main() {
  int t;
  cin >> t;
  if (t > 30) cout << "it's hot" << endl;
  else if (t < COLD) cout << "it's cold" << endl;
  else cout << "it's ok" << endl;
  if (t >= BOIL) cout << "water would boil" << endl;
  else if (t <= FREEZE) cout << "water would freeze" << endl;
}