#include <bits/stdc++.h>
using namespace std;

int main() {
    double x, result = 0;
    cin >> x;
    double n;
    vector <double> v(1000000);
    int i = 0;
    for (; cin >> n; ++i) v[i] = n;
    for (int j = i-1; j >= 0; --j) {result += pow(x, i-j-1)*v[j]; }
    cout << setprecision(4) << fixed << result << endl;
}
