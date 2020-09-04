#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  while (cin >> n) {
    vector <char> v(n);
    int greenDiff = 0;
    int whiteDiff = 0;
    int greenLowestDiff = 0;
    int whiteLowestDiff = 0;
    int greenPos = 0;
    int whitePos = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      if (v[i] == 'V') {
        --greenDiff;
        ++whiteDiff;
        if (greenLowestDiff > greenDiff) {
          greenLowestDiff = greenDiff;
          greenPos = i;
        }
      }
      else {
        ++greenDiff;
        --whiteDiff;
        if (whiteLowestDiff > whiteDiff) {
          whiteLowestDiff = whiteDiff;
          whitePos = i;
        }
      }
    }
    char startColor = 'V';
    int partition = greenPos;
    if (whiteLowestDiff < greenLowestDiff) {
      startColor = 'B';
      partition = whitePos;
    }
    int count = 0;
    for (int i = 0; i <= partition; ++i) if (v[i] != startColor) ++count;
    if (partition < n-1) for (int i = partition+1; i < n; ++i) if (v[i] == startColor) ++count;
    cout << count << endl;
  }
}
