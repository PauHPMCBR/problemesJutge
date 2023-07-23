#include <iostream>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  // Read the value of n from the standard input.
  int n;
  while(cin >> n){
    if (n == 0) cout << "With 0 term(s) we get 0.0000000000." << endl;
    else {

  // Initialize the approximation of e to 1.
  double e = 0;

  // Initialize the factorial to 1.
  double factorial = 1.0;

  // Compute the approximation of e by adding the n first terms of the Taylor series.
  for (int i = 0; i < n; ++i) {
    // Compute the i-th term of the Taylor series.
    double term = 1.0 / factorial;

    // Add the i-th term to the approximation of e.
    e += term;

    // Update the factorial.
    factorial *= (i + 1);
  }

  // Print the approximation of e.
  cout << "With " << n << " term(s) we get " << e << '.' << endl;
}
  }
}
