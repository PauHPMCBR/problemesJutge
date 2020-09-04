#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(double x, const vector<double>& v) {
  if (v.size() == 1) {
    if (v[0] == x) return 0;
    return -1;
  }
  if (v.size() == 2) {
    if (v[0] == x) return 0;
    if (v[1] == x) return 1;
    return -1;
  }
  int m = (v.size())/2;
  if (x == v[m]) return m;
  vector<double>::const_iterator begin = v.begin();
	vector<double>::const_iterator last = v.begin() + v.size();
  int pos = 0;
  if (x > v[m]) {begin = begin+m; pos += m;}
  else last = last-m;

  vector<double> w(begin, last);
  int n = first_occurrence(x, w);
  if (n == -1) return -1;
  else return (n+pos);
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
