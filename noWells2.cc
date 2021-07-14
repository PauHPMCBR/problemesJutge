#include <bits/stdc++.h>
using namespace std;
int n;



int main(){
	while (cin >> n){
		if (n == 1) cout << "(1)" << endl;
        else if (n == 2) cout << "(1,2)\n(2,1)" << endl;
        else if (n == 3) cout << "(1,2,3)\n(1,3,2)\n(2,3,1)\n(3,2,1)" << endl;
        else if (n == 4) cout << "(1,2,3,4)\n(1,3,4,2)\n(1,4,3,2)\n(2,3,4,1)\n(2,4,3,1)\n(4,3,2,1)" << endl;
        else {
            cout << '(';
            for (int i = 1; i < n; ++i) cout << i << ',';
            cout << n << ')' << endl;
            
            cout << '(';
            for (int i = 1; i <= n; ++i) if (i != 2) cout << i << ',';
            cout << 2 << ')' << endl;
            
            cout << '(';
            for (int i = 1; i <= n; i += 2) cout << i << ',';
            for (int i = (n/2)*2; i > 2; i -= 2) cout << i << ',';
            cout << 2 << ')' << endl;
            
            cout << '(' << 1;
            for (int i = n; i > 1; --i) cout << ',' << i;
            cout << ')' << endl;
            
            cout << '(';
            for (int i = 2; i <= n; ++i) cout << i << ',';
            cout << 1 << ')' << endl;
            
            cout << '(';
            for (int i = 2; i <= n; i += 2) cout << i << ',';
            for (int i = n+(n%2)-1; i > 1; i -= 2) cout << i << ',';
            cout << 1 << ')' << endl;
            
            cout << '(' << 2;
            for (int i = n; i > 2; --i) cout << ',' << i;
            cout << ',' << 1 << ')' << endl;
            
            cout << '(';
            for (int i = n; i > 1; --i) cout << i << ',';
            cout << 1 << ')' << endl;
            
        }
        cout << "----------" << endl;
	}
}
