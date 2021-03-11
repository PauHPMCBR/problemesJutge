#include <bits/stdc++.h>
using namespace std;
int h, n;
//vector<vector<int>>v;

int main(){
	cin >> h >> n;
	//v = vector<vector<int>>(n);
	int a,b,c;
	vector<int>t(n);
	vector<int>p(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		//v[i] = {a,b,c};
		if (i == 0) {t[0] = c; p[0] = b;}
		else {t[i] = t[i-1]+c; p[i] = p[i-1]+b;}
	}
	int maxP = 0;
	int minT = 0;
	int p1, p2;
	a = 0;
	b = 0;
	do {

		if (t[b]-t[a] > 55*h + 10*int((b-a)/5)) {
			if (a == b) ++b;
			++a;
		}
		else {
			//cout << a << ' ' << b << ' ' << t[b]-t[a] << endl;
			if (p[b]-p[a] > maxP) {
				maxP = p[b]-p[a];
				p1 = a;
				p2 = b;
				minT = t[b]-t[a];
			}
			else if (p[b]-p[a] == maxP) {
				if (t[b]-t[a]+10*int((b-a)/5) < minT) {
					maxP = p[b]-p[a];
					p1 = a;
					p2 = b;
					minT = t[b]-t[a]+10*int((b-a)/5);
				}
			}
			++b;
		}
	} while (a < n && b < n);

	cout << "Maximum points to achieve: " << maxP << 
		", by solving " << p2-p1 << " problem(s):" << endl;

	bool mobe = true;
	for (int i = p1+2; i <= p2+1; ++i)  {
		if (mobe) mobe = false;
		else cout << ' ';
		cout << i;
	}
	cout << endl;
}