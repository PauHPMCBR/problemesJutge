#include <iostream>
using namespace std;


int main() {
  char a;
  int e=0,c=0;
  bool changed = 0;
  int augm = 0;
  while (cin >> a) {
      if (a == '.') changed = true;
      else if (changed) {c*=10; c+=int(a-'0');++augm;}
      else {e*=10;e+=int(a-'0');}
  }
  if (augm == 1) c *= 10;
  cout << "Banknotes of 500 euros: " << (e/500) << endl;
  cout << "Banknotes of 200 euros: " << ((e%500)/200) << endl;
  cout << "Banknotes of 100 euros: " << (((e%500)%200)/100) << endl;
  cout << "Banknotes of 50 euros: " << ((e%100)/50) << endl;
  cout << "Banknotes of 20 euros: " << ((e%50)/20) << endl;
  cout << "Banknotes of 10 euros: " << (((e%50)%20)/10) << endl;
  cout << "Banknotes of 5 euros: " << ((e%10)/5) << endl;
  cout << "Coins of 2 euros: " << ((e%5)/2) << endl;
  cout << "Coins of 1 euro: " << ((e%5)%2) << endl;
  cout << "Coins of 50 cents: " << (c/50) << endl;
  cout << "Coins of 20 cents: " << ((c%50)/20) << endl;
  cout << "Coins of 10 cents: " << (((c%50)%20)/10) << endl;
  cout << "Coins of 5 cents: " << ((c%10)/5) << endl;
  cout << "Coins of 2 cents: " << ((c%5)/2) << endl;
  cout << "Coins of 1 cent: " << ((c%5)%2) << endl;
}
