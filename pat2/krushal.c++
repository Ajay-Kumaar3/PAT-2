#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
  int u, v, weight;
};

bool compare(Edge a, Edge b)
{
  return a.weight < b.weight;
}

int findParent(int parent[], int x)
{
  if (parent[x] == x)
    return x;

  return parent[x] = findParent(parent, parent[x]);
}

void join(int parent[], int a, int b)
{
  a = findParent(parent, a);
  b = findParent(parent, b);

  parent[b] = a;
}

int main()
{
  int n = 4;

  vector<Edge> edges =
      {
          {0, 1, 2}, // A-B
          {0, 2, 3}, // A-C
          {0, 3, 1}, // A-D
          {1, 3, 4}, // B-D
          {2, 3, 5}  // C-D
      };

  sort(edges.begin(), edges.end(), compare);

  int parent[4];

  for (int i = 0; i < n; i++)
    parent[i] = i;

  int totalCost = 0;

  cout << "Edges in MST:\n";

  for (Edge e : edges)
  {
    int a = findParent(parent, e.u);
    int b = findParent(parent, e.v);

    // If different groups, adding edge won't create cycle
    if (a != b)
    {
      cout << char('A' + e.u) << " - "
           << char('A' + e.v)
           << " : " << e.weight << endl;

      totalCost += e.weight;

      join(parent, a, b);
    }
  }

  cout << "Minimum Cost = " << totalCost << endl;

  return 0;
}

// Algorithm
// Sort all edges in increasing order of weight.
// Start with an empty MST.
// Pick the cheapest edge.
// Check whether adding it creates a cycle.
// If no cycle → add it.
// If cycle → reject it.
// Continue until V-1 edges are selected.

// Kruskal(graph)

//     sort all edges by increasing weight

//     create empty MST

//     for each edge (u,v)

//         if u and v belong to different sets

//             add edge to MST

//             union(u,v)

//         if MST contains V-1 edges
//             break

// Sorting = O(E log E)