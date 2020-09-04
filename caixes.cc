#include <iostream>
using namespace std;

int main(){
    int m, g, q, a, k, b;
    while (cin >> m >> g >> q >> a >> k >> b) {
      bool possible = false;
      bool caixa1 = false;
      bool caixa2 = false;
      if (g > m) {
        int prov = m;
        m = g;
        g = prov;
      }
      if (m % a == 0 && m/a <= q) caixa1 = true;
      if (m % b == 0 && m/b <= k) caixa2 = true;

      if (caixa1) {
        if (g % b == 0 && g/b <= k) possible = true;
      }

      if (caixa2) {
        if (g % a == 0 && g/a <= q) possible = true;
      }


      if (possible) cout << "Enviat" << endl;
      else cout << "Error" << endl;
    }
}
