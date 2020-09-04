#include <bits/stdc++.h>
using namespace std;

int maxim;

void blank() {
    cout << "  ";
}

void triangle(bool upperPart) {
    if (upperPart) cout << "##";
    else cout << " #";
}

void sierpinski(int n) {
    if (n == 0) return;
    sierpinski(n-1);
    for (int i = 0; i < maxim; ++i) {
        if (i < n) blank();
        else triangle(true);
    }
    cout << endl;
    for (int i = 0; i < maxim; ++i) {
        if (i < n) blank();
        else triangle(false);
    }
    cout << endl;
    
}

int main() {
    int n;
    cin >> n;
    maxim = n;
    sierpinski(n);
}
