#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<pair<double,double>>v(10);
	for(int i = 0; i < 10; i++){
		cin >> v[i].second;
	}
	for(int i = 0; i < 10; i++){
		cin >> v[i].first;
	}
	int maxim = 0;
	int a,b;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (i == j) continue;
			if (v[i].first+v[j].first <= 3) {
				if (v[i].second+v[j].second > maxim) {
					a = min(i,j);
					b = max(i,j);
					maxim = v[i].second+v[j].second;
				}

			}
		}
	}
	cout << "Mario chooses: prize " << a << " and prize " << b << " with a total profit of " << maxim << " EUR" << endl;
}