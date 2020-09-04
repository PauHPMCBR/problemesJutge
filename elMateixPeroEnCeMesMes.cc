#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
        for (int i = 2; i*i <= n; ++i) if (n%i == 0) return false;
        return true;
    }
    
bool is_perfect_prime(int n) {
        if (n < 2) return false;
        bool thisPrime = is_prime(n);
        if (n < 10) return thisPrime;
        int newNumber = 0;
        do {
            newNumber += n%10;
            n /= 10;
        }while(n >= 1);
        
        return is_perfect_prime(newNumber) && thisPrime;
    }
    
    
int main() {
    int n;
    cin >> n;
    cout << is_perfect_prime(n) << endl;
}
