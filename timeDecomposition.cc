#include <iostream>
using namespace std;

const int SEC_IN_HOUR = 3600;
const int SEC_IN_MIN = 60;

int main() {
  int n;
  cin >> n;
  cout << (n/SEC_IN_HOUR) << " ";
  cout << ((n%SEC_IN_HOUR)/SEC_IN_MIN) << " ";
  cout << (n%SEC_IN_MIN);
  cout << endl;
}