#include <bits/stdc++.h>
using namespace std;

void sort3(int& a, int& b, int& c) {
    vector<int>v = {a,b,c};
    sort(v.begin(), v.end());
    a = v[0], b = v[1], c = v[2];
}
