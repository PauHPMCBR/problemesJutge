#include <bits/stdc++.h>
using namespace std;
int total = 0;
int b(int n, int m){
	if (n == 3 || m == 3) {
		++total;
		if (n == 2 || m == 2) return 1;
		else return 0;
	}
	int s =0;
	s += b(n+1, m);
	s += b(n, m+1);
	return s;
}


int main(){
	cout << b(0, 0) << ' ' << total << endl;
}