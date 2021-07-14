#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    while (cin >> a >> b >> c) {
        vector<int>v = {a,b,c};
        sort(v.begin(), v.end());
        if (v[0]*v[0] + v[1]*v[1] == v[2]*v[2]) cout << v[1]*v[0]/2 << endl;
        else if (v[0]+v[1] > v[2]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
