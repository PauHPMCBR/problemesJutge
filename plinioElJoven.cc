#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int x = stoi(s.substr(6, 4));


		if (s.substr(0,6) == "29/02/") x += 4-(x%4);
		else {
			if (s.substr(3,2) > "02") x += 4-(x%4);
			else x += (4-(x%4))%4;
		}


		cout << "29/02/";
		if (x < 1000) cout << 0;
		if (x < 100) cout << 0;
		if (x < 10) cout << 0;
		cout << x << endl;
	}
}