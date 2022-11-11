#include <iostream>
using namespace std;

int main() {
  int n, m;
  int suma = 0;
  cin >> n;
  m = n;
  while(n!=0) {
    string s;
    cin >> s;
    suma += int(s[n-1])-'0';
    if (m%2==1) {
    if (m/2+1 != n) suma += int(s[m-n])-'0';
  }
  else suma += int(s[m-n])-'0';
    --n;
  }
  cout << suma << endl;
}