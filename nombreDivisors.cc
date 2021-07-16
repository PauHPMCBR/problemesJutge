#include <bits/stdc++.h>
using namespace std;

vector<int>divs(1e6+1, 2);

void garbell() {
    for (int i = 2; i < 1e6+1; ++i) {
        for (int j = 2*i; j < 1e6+1; j+=i) ++divs[j];
    }
}

int main() {
    divs[1] = 1;
    garbell();
    int n;
    while (cin >> n) cout << divs[n] << endl;
}
