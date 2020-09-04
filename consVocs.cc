#include <iostream>
#include <vector>
using namespace std;

int n;
vector <char> letters;
vector <bool> used;
vector <int> v;

void escriu() {
  for (int i = 0; i < n*2; ++i) {
    cout << letters[v[i]];
  }
  cout << endl;
}

void lol(int p){
  if (p == n*2) return escriu();
  int add = 0;
  if (p%2 == 1) add = n;
  for (int i = 0; i < n; ++i) {
    if (!used[i+add]){
      used[i+add] = true;
      v[p] = i+add;
      lol(p+1);
      used[i+add] = false;
    }
  }
}

int main() {
  cin >> n;
  letters = vector <char>(n*2);
  v = vector <int>(n*2);
  used = vector <bool>(n*2, false);
  for (int i = 0; i < n*2; ++i) cin >> letters[i];
  lol(0);
}
