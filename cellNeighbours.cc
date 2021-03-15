#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,x,y;
	cin >> n >> x >> y;
	int nei = 4;
	if (x < 2 || x >= n) --nei;
	if (y < 2 || y >= n) --nei;
	cout << nei << endl;
}