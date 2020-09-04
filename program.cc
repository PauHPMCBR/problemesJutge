#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

int main() {
  long long cat[68];
  memset(cat, 0, sizeof(cat));
  cat[0] = 1;
  for(int i=0; i<68; ++i) {
    for(int j=0; j<i; ++j) {
      cat[i] += cat[j] * cat[i-1-j];
    }
  }
  int n;
  while(cin >> n) {
    if(n&1) cout << 0 << endl;
    else cout << cat[n/2] << '\n';
  }
}