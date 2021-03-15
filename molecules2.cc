#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long sum = 0;
    int p[n];
    vector<pair<int,int>>pos;
    vector<pair<int,int>>neg;
    int prov;
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) {
        cin >> prov;
        if (prov < 0) neg.push_back({p[i], prov});
        else pos.push_back({p[i], prov});
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long provSum = 0;
    int i2 = 0;
    if (neg.size() != 0) {
        for (int i = 0; i < pos.size(); ++i) {
            while (i2 < int(neg.size()) && neg[i2].first < pos[i].first) {
                provSum += neg[i2].first;
                ++i2;
            }
            sum += (i2)*pos[i].first - provSum;
        }
    }

    for (int i = 0; i < pos.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (pos[i].second >= pos[j].second) sum += pos[i].first - pos[j].first;
        }
    }
    for (int i = 0; i < neg.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (neg[i].second >= neg[j].second) sum += neg[i].first - neg[j].first;
        }
    }

    cout << sum << endl;
}