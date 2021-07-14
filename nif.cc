#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char>v = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int n;
    cin >> n;
    cout << n << v[n%23] << endl;
}

