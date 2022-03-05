#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin >> a>> b >> c;
	bool pos = 1;
	if (a < 5 ||b < 2 || c < 50) pos = 0;
	cout << (pos ? "You can run the game" : "You can NOT run the game") << endl;
}