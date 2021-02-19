#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>cost;
vector<vector<ll>>adj;
main() {
   ll vert, edge, i, j, k, c;
   cout << "Enter no of vertices: ";
   cin >> vert;
   cout << "Enter no of edges: ";
   cin >> edge;
   cout << "Enter the EDGE Costs:\n";
   for (k = 1; k <= edge; k++) { //take the input and store it into adj and cost matrix
      cin >> i >> j >> c;
      adj[i][j] = cost[i][j] = c;
   }
   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++) {
         if (adj[i][j] == 0 && i != j)
            adj[i][j] = LLONG_MAX; //if there is no edge, put LLONG_MAXinity
      }
   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); //find minimum path from i to j through k
   cout << "Resultant adj matrix\n";
   for (i = 1; i <= vert; i++) {
      for (j = 1; j <= vert; j++) {
            if (adj[i][j] != LLONG_MAX)
               cout << adj[i][j] << " ";
      }
      cout << "\n";
   }
}