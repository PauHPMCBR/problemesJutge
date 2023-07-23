#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
vector<pair<int,int>> matches;
void b(int i, vector<vector<int>>& grid) {
    if (i <= 0) {
        cout << ans << '\n';
        return;
    }
    int n = grid.size();
    int best = 0, k = 0;
    for (int j = 0; j < i; ++j) {
        if (grid[i][j] > best) {
            best = grid[i][j];
            k = j;
        }
    }
    ans += best;
    for (int j = 0; j < n; ++j) {
        grid[k][j] = max(grid[k][j], grid[i][j]);
        grid[j][k] = max(grid[j][k], grid[j][i]);
    }
    matches.push_back({i, k});
    b(i-1, grid);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
        cin >> grid[i][j];
  }
  b(n-1, grid);
  for (auto x: matches) cout << x.first+1 << ' ' << x.second+1 << '\n';
}