#include <bits/stdc++.h>
using namespace std;

bool isPrime (int n){
	if (n < 2) return false;
	if (n == 2) return true; if (n % 2 == 0) return false;
	for(int i = 3; i*i <= n; i += 2) if(n % i == 0) return false; 
		return true;
}

vector<int>primes;


int main(){
	for (int i = 2; i < 100000; ++i) if (isPrime(i)) primes.push_back(i);
	int esq = 0, dre = 0;
	for (int i = 3; i < 100; ++i) {
		while (primes[esq] < i*i/2) ++esq;
		while (primes[dre] < i*i) ++dre;
		cout << i << ": " << dre-esq << "  ";
		if (dre-esq <= i) cout << "!!!!!!!!!!!!!!!!!!";
		//for (int j = esq; j < dre; ++j) cout << primes[j] << ' ';
		cout << endl;
	}
}