#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == '0') {
        s[0] = s[1];
        s[1] = '0';
    }
    if (s[0] == '0') {
        s[0] = s[2];
        s[2] = '0';
    }
    cout << s << endl;
}
