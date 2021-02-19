#include <bits/stdc++.h>
using namespace std;

vector<int>p;

bool isPrime (int n){
	if (n < 2) return false;
	if (n == 2) return true; if (n % 2 == 0) return false;
	for(int i = 3; i*i <= n; i += 2) if(n % i == 0) return false; 
	return true;
}

void getPrimes() {
	for (int i = 2; i < 10000; ++i) {
		if (isPrime(i)) v.push_back(i);
	}
}

int main(){
	int it = 0;
	for (int i = 2; i < 100000; ++i) {
		
	}
}