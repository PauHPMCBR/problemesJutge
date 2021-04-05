#include <bits/stdc++.h>
using namespace std;

vector <long long> z(151, -1);
vector <long long> u(151, -1);
vector <long long> x(151, -1);
vector <long long> sum(151, -1);



void bits(long long n) {
    if (sum[n] != -1) return;
    bits(n-1);
    z[n] = x[n-1] + u[n-1];
    x[n] = u[n-1];
    u[n] = z[n-1];
    sum[n] = z[n] + x[n] + u[n];
   	//cout << n << " done" << endl;
}

int main() {
    long long n;
    
    z[0] = 1;
    u[0] = 0;
    x[0] = 0;
    z[1] = 1;
    u[1] = 1;
    x[1] = 0;
    sum[0] = 1;
    sum[1] = 2;
    while (cin >> n) {
    	bits(n);
    	cout << sum[n] << endl;
    }
}
