#include <bits/stdc++.h>
using namespace std;

int main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int d1 = max(0, abs(x1-x2)-1);
	int d2 = max(0, abs(y1-y2)-1);
	cout << 8+2*d1+2*d2 << endl;
}