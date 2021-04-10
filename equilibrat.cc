#include <bits/stdc++.h>
using namespace std;

bool es_equilibrat(int n) {
	int s = 0, t = 0;
	bool b = true;
	while (n > 0) {
		if (b) s += n%10;
		else t += n%10;
		b = !b;
		n /= 10;
	}
	return s == t;
}

int main(){
	int n;
	cin >> n;
	cout << es_equilibrat(n) << endl;
}