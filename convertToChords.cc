#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    int n = int(s[i] - 'a');
    n = n%7;
    cout << char(n + 'a');
  }
  cout << endl;

}
