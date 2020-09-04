#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//si es pes i no massa deuen ser molt petitets tots

int main(){
  int n;
  while (cin >> n) {
    vector <int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int max = 0;
    int maxweight = v[0];
    int current = v[0];
    int count = 1;
    for (int i = 1; i < n; ++i) {
      if (v[i] == current) ++count;
      else {
        if (count >= max) {
          max = count;
          maxweight = current;
        }
        current = v[i];
        count = 1;
      }
    }
    if (count >= max) {
      max = count;
      maxweight = current;
    }

    cout << max << ' ' << maxweight << endl;
  }
}
