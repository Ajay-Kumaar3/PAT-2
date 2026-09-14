#include <iostream>
#include <vector>
using namespace std;

#define INF 9999

int main()
{
  int n = 4;

  int graph[4][4] =
      {
          {0, 2, 3, 1},
          {2, 0, INF, 4},
          {3, INF, 0, 5},
          {1, 4, 5, 0}};

  bool visited[4] = {false};

  visited[0] = true; // Start from A

  int totalCost = 0;

  cout << "Edges in MST:\n";

  for (int count = 0; count < n - 1; count++)
  {
    int minEdge = INF;
    int u = -1;
    int v = -1;

    // Find cheapest edge
    for (int i = 0; i < n; i++)
    {
      if (visited[i])
      {
        for (int j = 0; j < n; j++)
        {
          if (!visited[j] && graph[i][j] < minEdge)
          {
            minEdge = graph[i][j];
            u = i;
            v = j;
          }
        }
      }
    }

    visited[v] = true;

    cout << char('A' + u) << " - "
         << char('A' + v)
         << " : " << minEdge << endl;

    totalCost += minEdge;
  }

  cout << "Minimum Cost = " << totalCost << endl;

  return 0;
}


// Algorithm
// Select any starting vertex.
// Mark it visited.
// Find the minimum-weight edge connecting:
// a visited vertex
// an unvisited vertex
// Add that edge to MST.
// Mark the new vertex visited.
// Repeat until V-1 edges are selected.

// Prim(graph)

//     choose starting vertex

//     mark it visited

//     repeat V-1 times

//         minEdge = INF

//         for every visited vertex u

//             for every unvisited vertex v

//                 if edge(u,v) < minEdge

//                     minEdge = edge(u,v)
//                     remember u,v

//         add edge(u,v) to MST

//         mark v visited

// O(V²)