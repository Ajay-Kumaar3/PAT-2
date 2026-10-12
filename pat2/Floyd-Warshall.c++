#include <iostream>
using namespace std;

#define INF 9999

int main()
{
  int n = 4;

  int dist[4][4] =
      {
          {0, 5, 9, INF},
          {INF, 0, 2, 8},
          {INF, INF, 0, 3},
          {INF, INF, INF, 0}};

  // Try every vertex as an intermediate vertex
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dist[i][k] + dist[k][j] < dist[i][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }

  cout << "Shortest Distance Matrix:\n\n";

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (dist[i][j] == INF)
        cout << "INF ";
      else
        cout << dist[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}


// Algorithm
// Create a distance matrix.
// Set:
// 0 for same vertex
// edge weight for connected vertices
// INF for no direct edge
// Consider every vertex as an intermediate vertex.
// Check whether going through that vertex gives a shorter path.
// Update the distance matrix.


// FloydWarshall(dist)

//     for k = 0 to V-1

//         for i = 0 to V-1

//             for j = 0 to V-1

//                 if dist[i][k] + dist[k][j]
//                    < dist[i][j]

//                     dist[i][j] =
//                     dist[i][k] + dist[k][j]


// Time  = O(V³)
// Space = O(V²)