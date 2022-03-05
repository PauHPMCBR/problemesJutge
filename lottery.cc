#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	if (((n*10)/m)%10 != 0 && ((n*100)/m%10 == 0)) cout << 1 << endl;
	else cout << 0 << endl;
}