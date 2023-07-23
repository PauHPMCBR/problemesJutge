#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> PT;

double distPoint(PT a, PT b) {
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
double cross(PT a, PT b) {
    return a.first*b.second - a.second*b.first;
}

double polygonDiameter(vector<PT> &p) {
    int n = p.size();
    if (n < 2) return 0;
    if (n == 2) return distPoint(p[0], p[1]);

    int i = n-1, j = 0, k = 1;
    double res = 0;
    PT sj = {p[j].first-p[i].first, p[j].second-p[i].second};
    PT sk = {p[k].first-p[i].first, p[k].second-p[i].second};
    PT sk1 = {p[k+1].first-p[i].first, p[k+1].second-p[i].second};
    while (abs(cross(sj,sk1) > abs(cross(sj,sk)))) {
        ++k;
        sk = {p[k].first-p[i].first, p[k].second-p[i].second};
        sk1 = {p[k+1].first-p[i].first, p[k+1].second-p[i].second};
    }
    i = 0, j = k;
    while (i <= k && j < n) {
        res = max(distPoint(p[i],p[j]), res);

        PT sj1 = {p[j+1].first-p[i].first, p[j+1].second-p[i].second};
        sj = {p[j].first-p[i].first, p[j].second-p[i].second};
        PT si1 = {p[i+1].first-p[i].first, p[i+1].second-p[i].second};
        while (j < n-1 && abs(cross(si1,sj1) > abs(cross(si1,sj)))) {
            ++j;
            sj1 = {p[j+1].first-p[i].first, p[j+1].second-p[i].second};
            sj = {p[j].first-p[i].first, p[j].second-p[i].second};
            si1 = {p[i+1].first-p[i].first, p[i+1].second-p[i].second};
            res = max(distPoint(p[i],p[j]), res);
        }
        ++i;
        sj1 = {p[j+1].first-p[i].first, p[j+1].second-p[i].second};
        sj = {p[j].first-p[i].first, p[j].second-p[i].second};
        si1 = {p[i+1].first-p[i].first, p[i+1].second-p[i].second};
    }
    return res;
}

int main() {
    vector<PT>v = {{1,1}, {2,2}, {4,3}, {5,1}, {2,-2}};
    cout << polygonDiameter(v) << endl;
}