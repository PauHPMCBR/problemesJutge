#include <iostream>
using namespace std;

const int SEC_IN_HOUR = 3600;
const int SEC_IN_MIN = 60;

void decompose(int n, int& h, int& m, int& s) {
  h = (n/SEC_IN_HOUR);
  m = ((n%SEC_IN_HOUR)/SEC_IN_MIN);
  s = (n%SEC_IN_MIN);
}

