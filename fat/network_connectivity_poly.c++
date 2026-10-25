
#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E, B;
    cin >> V >> E >> B;

    vector<int> u(E + 1), v(E + 1), cost(E + 1);

    for (int i = 1; i <= E; i++)
        cin >> u[i] >> v[i] >> cost[i];

    int M;
    cin >> M;

    vector<vector<int>> adj(V + 1);
    int totalCost = 0;

    for (int i = 0; i < M; i++) {
        int id;
        cin >> id;

        adj[u[id]].push_back(v[id]);
        adj[v[id]].push_back(u[id]);
        totalCost += cost[id];
    }

    vector<bool> visited(V + 1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    bool connected = true;

    for (int i = 1; i <= V; i++) {
        if (!visited[i])
            connected = false;
    }

    bool budgetOK = totalCost <= B;

    cout << "Total Installation Cost: " << totalCost << '\n';
    cout << "Connectivity: "
         << (connected ? "Connected" : "Disconnected") << '\n';
    cout << "Budget Constraint: "
         << (budgetOK ? "Satisfied" : "Violated") << '\n';

    if (connected && budgetOK)
        cout << "Certificate Verification: ACCEPTED\n";
    else
        cout << "Certificate Verification: REJECTED\n";

    return 0;
}


//Algorithm
// 1. Read the stations, available links, budget, and link costs.
// 2. Read the certificate containing selected link IDs.
// 3. Build an adjacency list from the selected links and calculate their total cost.
// 4. Run BFS from station 1.
// 5. Check whether every station has been visited.
// 6. Check whether the total cost is within the budget.
// 7. Accept if the network is connected and within budget; otherwise, reject.
// Pseudocode
// VERIFY-NETWORK(V, E, B, edges, certificate):

//     totalCost = 0
//     adj = empty graph

//     for each selected edge ID:
//         add edge to adj
//         totalCost = totalCost + edge cost

//     Run BFS from station 1

//     connected = all stations visited
//     budgetOK = (totalCost <= B)

//     if connected AND budgetOK:
//         return ACCEPTED
//     else:
//         return REJECTED


// Complexity
// - Time: \(O(V+E)\)
// - Space: \(O(V+E)\)