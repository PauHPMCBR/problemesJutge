#include <bits/stdc++.h>
using namespace std;

int main(){
	long long x1,y1,x2,y2,x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	long long dist = abs(x1-x2) + abs(y1-y2);
	if (x1 == x2 && x2 == x3) {
		if (y1 < y3 && y2 < y3);
		else if (y1 > y3 && y2 > y3);
		else dist += 2;
	}
	if (y1 == y2 && y2 == y3) {
		if (x1 < x3 && x2 < x3);
		else if (x1 > x3 && x2 > x3);
		else dist += 2;
	}
	cout << dist << endl;
}