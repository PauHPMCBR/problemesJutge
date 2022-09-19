#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int s=0, t=0;
	int prov;
	for (int i = 0; i < n; ++i) {
		cin >> prov;
		if (i%2 == 0) s+=prov;
		else t+=prov;
	}
	cout << max(s,t) << endl;
}