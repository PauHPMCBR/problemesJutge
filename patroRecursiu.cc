#include <bits/stdc++.h>
using namespace std;

void b(char c) {
    cout << c;
    for (int i = 0; i < int(c-'a'); ++i) {
        b(char(c-1));
        cout << c;
    }
}

int main() {
    char c;
    cin >> c;
    b(c);
    cout << endl;
}
