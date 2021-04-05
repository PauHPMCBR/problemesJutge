#include <bits/stdc++.h>
using namespace std;

int main(){
	//cout.precision(2);
	double k, m;
	cin >> k;
	vector<double>asks;
	vector<double>bids;
	vector<double>total;
	while (cin >> m) {
		if (m == -1) break;
		bids.push_back(m);
		total.push_back(m);
	}
	while (cin >> m) {
		if (m == -1) break;
		asks.push_back(m);
		total.push_back(m);
	}
	sort(total.begin(), total.end(), greater<>());
	double price = k*total[asks.size()] + (1-k)*total[asks.size()-1];
	cout << "Price: " << price << endl;
	cout << "Asks sold: ";
	bool mobe = true;
	sort(asks.begin(), asks.end());
	sort(bids.begin(), bids.end(), greater<>());
	for (auto i : asks) {
		if (i > price) break;
		if (mobe) mobe = false;
		else cout << ',';
		cout << i;
		if (i == int(i)) cout << ".0";
	}
	cout << endl << "Bids sold: ";
	mobe = true;
	for (auto i : bids) {
		if (i < price) break;
		if (mobe) mobe = false;
		else cout << ',';
		cout << i;
		if (i == int(i)) cout << ".0";
	}
	cout << endl;
}