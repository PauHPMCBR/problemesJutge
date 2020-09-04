#include <iostream>
using namespace std;

typedef long long ll;

//no funciona be xd
int main(){
    ll informats = 6;
    ll grup1 = 1;
    ll grup2 = 5;
    int ronda = 1;
    while (informats < 7776000000) {
      int nous = (grup1+grup2)*5;
      informats += nous;
      grup1 = grup2;
      grup2 = nous;
      ++ronda;
      cout << ronda << ": " << informats << endl;
    }
    cout << ronda << endl;
}
