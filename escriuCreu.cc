#include <bits/stdc++.h>
using namespace std;

void cross(int n, char c) {
    for (int i = 0; i < n/2; ++i) {
        cout << string(n/2, ' ') << c << endl;
    }
    cout << string(n, c) << endl;
    for (int i = 0; i < n/2; ++i) {
        cout << string(n/2, ' ') << c << endl;
    }
}
