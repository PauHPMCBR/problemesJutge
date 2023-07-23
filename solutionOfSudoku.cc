#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int k = 0; k < n; ++k) {
    vector<vector<int>>sudoku(9, vector<int>(9));
    bool possible = true;
    vector<bool>used(9, false);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        cin >> sudoku[i][j];
        if (used[sudoku[i][j]-1]) possible = false;
        else used[sudoku[i][j]-1] = true;
      }
      for (int l = 0; l < 9; ++l) used[l] = false;
    }

    for (int j = 0; j < 9; ++j) {
      for (int i = 0; i < 9; ++i) {
        if (used[sudoku[i][j]-1]) possible = false;
        else used[sudoku[i][j]-1] = true;
      }
      for (int l = 0; l < 9; ++l) used[l] = false;
    }

    for (int startx = 0; startx < 8; startx += 3) {
      for (int starty = 0; starty < 8; starty += 3) {

        for (int i = startx; i < startx+3; ++i) {
          for (int j = starty; j < starty+3; ++j) {
            if (used[sudoku[i][j]-1]) possible = false;
            else used[sudoku[i][j]-1] = true;
          }
        }
          for (int l = 0; l < 9; ++l) used[l] = false;

      }
    }

    if (possible) cout << "yes" << endl;
    else cout << "no" << endl;

  }
}