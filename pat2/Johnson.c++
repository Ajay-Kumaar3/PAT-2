#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF 999999

struct Edge
{
  int u, v, w;
};

// Bellman-Ford
bool bellmanFord(int V, vector<Edge> &edges,
                 int source, vector<int> &h)
{
  h.assign(V, INF);
  h[source] = 0;

  for (int i = 0; i < V - 1; i++)
  {
    for (Edge e : edges)
    {
      if (h[e.u] != INF &&
          h[e.u] + e.w < h[e.v])
      {
        h[e.v] = h[e.u] + e.w;
      }
    }
  }

  // Check negative cycle
  for (Edge e : edges)
  {
    if (h[e.u] != INF &&
        h[e.u] + e.w < h[e.v])
    {
      return false;
    }
  }

  return true;
}

// Dijkstra
vector<int> dijkstra(int V,
                     vector<vector<pair<int, int>>> &graph,
                     int source)
{
  vector<int> dist(V, INF);

  priority_queue<
      pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>>>
      pq;

  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty())
  {
    int d = pq.top().first;
    int u = pq.top().second;

    pq.pop();

    if (d != dist[u])
      continue;

    for (auto edge : graph[u])
    {
      int v = edge.first;
      int w = edge.second;

      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  return dist;
}

int main()
{
  int V = 4;

  vector<Edge> edges =
      {
          {0, 1, 4},
          {0, 2, 1},
          {2, 1, -2},
          {1, 3, 2},
          {2, 3, 5}};

  // Add dummy vertex
  int newV = V + 1;

  vector<Edge> newEdges = edges;

  for (int i = 0; i < V; i++)
    newEdges.push_back({V, i, 0});

  // Step 1: Bellman-Ford
  vector<int> h;

  if (!bellmanFord(newV, newEdges, V, h))
  {
    cout << "Negative cycle exists!" << endl;
    return 0;
  }

  // Step 2: Reweight edges
  vector<vector<pair<int, int>>> graph(V);

  for (Edge e : edges)
  {
    int newWeight = e.w + h[e.u] - h[e.v];

    graph[e.u].push_back({e.v, newWeight});
  }

  // Step 3: Dijkstra from every vertex
  cout << "All-Pairs Shortest Path:\n\n";

  for (int s = 0; s < V; s++)
  {
    vector<int> dist = dijkstra(V, graph, s);

    cout << "From " << char('A' + s) << ": ";

    for (int v = 0; v < V; v++)
    {
      if (dist[v] == INF)
        cout << "INF ";
      else
      {
        // Convert back to original distance
        int original =
            dist[v] - h[s] + h[v];

        cout << original << " ";
      }
    }

    cout << endl;
  }

  return 0;
}



// Algorithm
// Add a new dummy vertex S.
// Connect S to every vertex with weight 0.
// Run Bellman-Ford from S.
// Get h[v] values.
// Reweight every edge:
// w'(u,v) = w(u,v) + h[u] - h[v]
// Now all edge weights are non-negative.
// Run Dijkstra from every vertex.
// Convert the distances back:
// d(u,v) = d'(u,v) - h[u] + h[v]

// Johnson(graph)

//     add new vertex S

//     for every vertex v
//         add edge S → v with weight 0

//     h = BellmanFord(S)

//     if negative cycle
//         stop

//     for every edge (u,v,w)

//         w' = w + h[u] - h[v]

//     for every vertex u

//         dist' = Dijkstra(u)

//         for every vertex v

//             dist[u][v] =
//                 dist'[v] - h[u] + h[v]

//     return dist

// O(VE log V)