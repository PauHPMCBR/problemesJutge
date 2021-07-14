#include <bits/stdc++.h>
using namespace std;

void print(int s, char c, int n) {
    cout << string(s, ' ') << string(n, c) << endl;
}

int main() {
    int s,n;
    char c;
    cin >> s >> c >> n;
    print(s,c,n);
}
