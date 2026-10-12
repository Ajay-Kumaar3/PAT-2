#include <iostream>
#include <vector>
using namespace std;

#define INF 9999

struct Edge
{
  int u, v, weight;
};

int main()
{
  int V = 5;

  vector<Edge> edges =
      {
          {0, 1, 6},
          {0, 2, 7},
          {1, 2, 8},
          {1, 3, 5},
          {1, 4, -4},
          {2, 3, -3},
          {2, 4, 9},
          {3, 1, -2},
          {4, 3, 7}};

  int source = 0;

  int dist[5];

  // Initially all distances are infinity
  for (int i = 0; i < V; i++)
    dist[i] = INF;

  dist[source] = 0;

  // Relax all edges V-1 times
  for (int i = 1; i <= V - 1; i++)
  {
    for (Edge e : edges)
    {
      if (dist[e.u] != INF &&
          dist[e.u] + e.weight < dist[e.v])
      {
        dist[e.v] = dist[e.u] + e.weight;
      }
    }
  }

  // Check for negative cycle
  for (Edge e : edges)
  {
    if (dist[e.u] != INF &&
        dist[e.u] + e.weight < dist[e.v])
    {
      cout << "Negative cycle exists!" << endl;
      return 0;
    }
  }

  cout << "Shortest distances from A:\n";

  for (int i = 0; i < V; i++)
  {
    cout << "A -> " << char('A' + i)
         << " = " << dist[i] << endl;
  }

  return 0;
}


// Algorithm
// Set source distance to 0.
// Set all other distances to INF.
// Relax every edge V-1 times.
// After that, check every edge one more time.
// If any distance can still be reduced → negative cycle exists.


// BellmanFord(graph, source)

//     dist[source] = 0

//     for every other vertex
//         dist[v] = INF

//     repeat V-1 times

//         for every edge (u,v,w)

//             if dist[u] + w < dist[v]

//                 dist[v] =
//                 dist[u] + w

//     for every edge (u,v,w)

//         if dist[u] + w < dist[v]

//             print "Negative cycle"

//     return dist

// Time  = O(VE)
// Space = O(V)