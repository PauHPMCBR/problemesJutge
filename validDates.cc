#include <iostream>
using namespace std;

bool is_leap_year(int year) {
	if (year%400 == 0) return true;
	if (year%100 == 0) return false;
	if (year%4 == 0) return true;
	return false;
}

bool is_valid_date(int d, int m, int a) {
  if (is_leap_year(a)) {
    if ((d > 29) && (m == 2)) return false;
  }

  if (not(is_leap_year(a))) {
    if ((d > 28) && (m == 2)) return false;
  }

  if (d > 31) return false;
  if (not((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))) if (d > 30) return false;

  if (d < 1) return false;
  if ((m > 12) || (m < 1)) return false;
  return true;
}