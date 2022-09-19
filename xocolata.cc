#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    while (cin >> n >> m) {
      vector <int> v(n);
      vector <int> w(m);
      for (int i = 0; i < n; ++i) cin >> v[i];
      for (int i = 0; i < m; ++i) cin >> w[i];
      sort(v.begin(), v.end());
      sort(w.begin(), w.end());
      int plaer = 0;
      while (n > 0 && m > 0) {
        if (v[n-1] > w[m-1]) {
          plaer += v[n-1]*m;
          --n;
        }
        else {
          plaer += w[m-1]*n;
          --m;
        }
      }
      cout << plaer << endl;
    }
}
