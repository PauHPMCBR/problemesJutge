#include <iostream>
using namespace std;

struct Rectangle {
  int x_left, x_right, y_down, y_up;
};

Rectangle intersection(const Rectangle& r1, const Rectangle& r2) {
  Rectangle r;
  r.x_left = max(r1.x_left, r2.x_left);
  r.x_right = min(r1.x_right, r2.x_right);
  r.y_down = max(r1.y_down, r2.y_down);
  r.y_up = min(r1.y_up, r2.y_up);
  return r;
}

int main() {
  int n;
  cin >> n;
  while (n != 0) {
    Rectangle r;
    cin >> r.x_left >> r.x_right >> r.y_down >> r.y_up;
    for (int i = 1; i < n; ++i) {
      Rectangle temp;
      cin >> temp.x_left >> temp.x_right >> temp.y_down >> temp.y_up;
      r = intersection(r, temp);
    }
    if (r.x_left >= r.x_right || r.y_down >= r.y_up) {
      cout << "empty intersection" << endl;
    }
    else {
    	cout << "bottom left point = (" << r.x_left << ", " << r.y_down << "); top right point = (" << r.x_right << ", " << r.y_up << ")" << endl;
    }

    cin >> n;
  }
}
