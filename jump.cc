#include <string>
#include <vector>
using namespace std;

string exit(int p, vector<int>& v) {
  // Initialize the current position to p.
  int pos = p;

  // Loop until we go out of bounds or we reach a position that we have already visited.
  while (pos >= 0 && pos < v.size() && v[pos] != 0) {
    int sus = v[pos];
    // Save the current position in the vector v.
    v[pos] = 0;

    // Jump to the next position according to the value of v at the current position.
    pos += sus;
  }

  // Check if we went out of bounds on the left side.
  if (pos < 0) {
    return "left";
  }

  // Check if we went out of bounds on the right side.
  if (pos >= v.size()) {
    return "right";
  }

  // If we reached a position that we have already visited, the process never ends.
  return "never";
}
