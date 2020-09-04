#include <iostream>
#include <vector>
using namespace std;

int dre = -1;
int esq = -1;

int first_occurrence(double x, const vector<double>& v) {
    if (dre == -1) {
        dre = v.size()-1;
        esq = 0;
    }
  if (dre <= esq) {
    if (v[0] == x) return 0;
    return -1;
  }
  int mid = (esq+dre)/2;
  if (v[mid] == x) return mid;
  
  if (v[mid] < x) esq = mid;
  else dre = mid;
  int n = first_occurrence(x, v);
  if (n == -1) return -1;
  else return n;
}

int main(){
  double x;
  int n;
  cin >> x;
  cin >> n;
  vector <double> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  cout << first_occurrence(x, v) << endl;

}
