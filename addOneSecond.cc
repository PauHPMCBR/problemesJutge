#include <iostream>
using namespace std;

const int SEC = 60;
const int MIN = 60;
const int HOUR = 24;

int main() {
  int h, m, s;
  cin >> h >> m >> s;
  if ((s == SEC-1) and (m == MIN-1) and (h == HOUR-1)) {
    cout << "00" << ":" << "00" << ":" << "00" << endl;
  }
  else if ((s == SEC-1) and (m == MIN-1)) {
    if (h < 9) cout << 0;
    cout << (h+1) << ":";
    cout << "00" << ":" << "00" << endl;
   }
  else if (s == SEC-1) {
    if (h < 10) cout << 0;
    cout << h << ":";
    if (m < 9) cout << 0;
    cout << (m+1);
    cout << ":" << "00" << endl;
  }
  else {
    if (h < 10) cout << 0;
    cout << h << ":";
    if (m < 10) cout << 0;
    cout << m << ":";
    if (s < 9) cout << 0;
    cout << (s+1) << endl;
  }
}