#include <iostream>
#include <string>
using namespace std;

bool is_palindromic(int n) {
  string s = to_string(n);
  for (int i = 0; i < s.size(); ++i) {
    if (not(s[i]==s[s.size()-i-1])) return false;
  }
  return true;
}