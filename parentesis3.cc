#include <bits/stdc++.h>
using namespace std;

vector<char>v;

bool isInt(char c) {
    return (c <= '9' && c >= '0');
}

int endingPos = -1;
int f(int pos) {
    //cout << pos << endl;
    char c = v[pos];
    endingPos = pos;
    if (isInt(c)) return int(c-'0');
    if (c == '(') {
        int val1 = f(pos+1);
        int op = v[endingPos+1];
        int val2 = f(endingPos+2);
        ++endingPos;
        if (op == '+') return val1+val2;
        if (op == '-') return val1-val2;
        return val1*val2;
    }
    return -1;
}


int main() {
    char c;
    while (cin >> c) v.push_back(c);
    cout << f(0) << endl;
}
