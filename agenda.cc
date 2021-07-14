#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    map<string, int>m = {{"dilluns", 1}, {"dimarts", 2}, {"dimecres", 3}, {"dijous", 4}, {"divendres", 5}, {"dissabte",6 }, {"diumenge", 7}};
    int a = m[s1], b = m[s2];
    if (a > b) {
        if (a-b > 3) cout << 'A' << endl;
        else cout << 'B' << endl;
    }
    else {
        if (b-a > 3) cout << 'B' << endl;
        else cout << 'A' << endl;
    }
}
