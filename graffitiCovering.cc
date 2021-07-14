#include <bits/stdc++.h>
using namespace std;


int main() {
    int g, p;
    while (cin >> g) {
        vector <int> v(g);
        for (int i = 0; i < g; ++i) cin >> v[i];
        cin >> p;
        if (p >= g) cout << p << endl;
        else {
            sort(v.begin(), v.end());
            
            int dre = (v[g-1]-v[0])/p + 1;
            int esq = 1;
            
            while (esq < dre) {
                int mid = (esq+dre)/2;
                //cout << esq << ' ' << mid << ' ' << dre << endl;
                
                int used = 0;
                int pos = mid*(-2);
                for (int i = 0; i < g && used <= p; ++i) {
                    if (pos+mid-1 < v[i]) {
                        ++used;
                        pos = v[i];
                    }
                }
                if (used <= p) dre = mid;
                else esq = mid+1;
            }
            cout << dre*p << endl;
        }
    }
}
