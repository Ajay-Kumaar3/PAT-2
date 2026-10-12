
#include <bits/stdc++.h>
using namespace std;

int c[6][6], vis[6];

// DFS finds an augmenting path
int dfs(int u, int t, int flow)
{
  if (u == t)
    return flow;
  vis[u] = 1;

  for (int v = 0; v < 6; v++)
  {
    if (!vis[v] && c[u][v] > 0)
    {
      int f = dfs(v, t, min(flow, c[u][v]));

      if (f > 0)
      {
        c[u][v] -= f; // Reduce forward capacity
        c[v][u] += f; // Increase reverse capacity
        return f;
      }
    }
  }
  return 0;
}

int main()
{
  int e[][3] = {
      {0, 1, 14}, {0, 2, 8}, {1, 2, 10}, {1, 3, 12}, {2, 4, 11}, {3, 2, 3}, {3, 5, 15}, {4, 3, 5}, {4, 5, 9}};

  for (auto &x : e)
    c[x[0]][x[1]] = x[2];

  int flow, maxFlow = 0;

  while (true)
  {
    memset(vis, 0, sizeof(vis));
    flow = dfs(0, 5, 1e9);

    if (flow == 0)
      break;
    maxFlow += flow;
  }

  cout << "Maximum Flow = " << maxFlow << endl;
  return 0;
}

// Algorithm:

// 1. Initialize maximum flow \(F = 0\).
// 2. Initialize the residual graph with the original capacities.
// 3. Find an augmenting path from source \(S\) to sink \(T\) using DFS.
// 4. Find the minimum residual capacity along the path (bottleneck).
// 5. Update the residual capacities:
//    - Subtract the bottleneck from forward edges.
//    - Add the bottleneck to reverse edges.
// 6. Add the bottleneck to \(F\).
// 7. Repeat steps 3–6 until no augmenting path exists.
// 8. Return \(F\) as the maximum flow.

// Pseudocode :

// FORD-FULKERSON(G, S, T):
//     F = 0
//     Initialize residual graph R = G

//     while an augmenting path P exists from S to T in R:
//         bottleneck = minimum residual capacity along P

//         for each edge (u, v) in P:
//             R[u][v] = R[u][v] - bottleneck
//             R[v][u] = R[v][u] + bottleneck

//         F = F + bottleneck

//     return F

// O(E.Fmax) - TIME COMPLEXITY
