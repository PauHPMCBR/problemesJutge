#include <bits/stdc++.h>
using namespace std;

vector <bool> l(42, false);

int main() {
    int input;
    int counter = 0;
    for (int i = 0; i < 10; ++i) {
        cin >> input;
        if (!l[input%42]) {
            l[input%42] = true;
            ++counter;
        }
    }
    cout << counter << endl;
    
}
