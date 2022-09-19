#include <iostream>
using namespace std;

const int DAYS = 365;
const int HOURS = 24;
const int MINUTES = 60;
const int SECONDS = 60;

int main() {
  int any, dia, hora, minut, segon;
  cin >> any >> dia >> hora >> minut >> segon;
  dia += any*DAYS;
  hora += dia*HOURS;
  minut += hora*MINUTES;
  segon += minut*SECONDS;
  cout << segon << endl;
}