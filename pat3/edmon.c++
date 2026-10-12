
#include <bits/stdc++.h>
using namespace std;

int c[6][6], p[6];
string name[] = {"S","A","B","C","D","T"};

// BFS finds an augmenting path
int bfs() {
    fill(p, p+6, -1);
    queue<pair<int,int>> q;
    q.push({0, 1e9});
    p[0] = 0;

    while (!q.empty()) {
        auto [u, f] = q.front();
        q.pop();

        for (int v=0; v<6; v++) {
            if (p[v]==-1 && c[u][v]>0) {
                p[v] = u;
                int nf = min(f, c[u][v]);

                if (v==5) return nf;
                q.push({v, nf});
            }
        }
    }
    return 0;
}

int main() {
    int e[][3] = {
        {0,1,14}, {0,2,8}, {1,2,10},
        {1,3,12}, {2,4,11}, {3,2,3},
        {3,5,15}, {4,3,5}, {4,5,9}
    };

    for (auto &x : e)
        c[x[0]][x[1]] = x[2];

    int flow, maxFlow=0, it=1;

    cout << "=== Augmenting Path Iterations ===\n";

    while ((flow = bfs()) > 0) {
        vector<int> path;

        for (int v=5; v!=0; v=p[v]) {
            path.push_back(v);
            c[p[v]][v] -= flow;
            c[v][p[v]] += flow;
        }

        path.push_back(0);
        reverse(path.begin(), path.end());

        cout << "Iteration " << it++ << ": Path = ";
        for (int i=0; i<path.size(); i++) {
            cout << name[path[i]];
            if (i+1<path.size()) cout << " -> ";
        }

        maxFlow += flow;
        cout << " | Bottleneck = " << flow
             << " | Cumulative Flow = " << maxFlow << '\n';
    }

    cout << "\nMaximum Oxygen Delivery Rate from S to T: "
         << maxFlow << " L / min\n";

    return 0;
}


// Algorithm
// 1. Initialize the residual capacity matrix with the original edge capacities.
// 2. Set maximum flow to zero.
// 3. Use BFS to find the shortest augmenting path from source \(S\) to sink \(T\).
// 4. Find the bottleneck capacity (minimum residual capacity along the path).
// 5. Update the forward and reverse residual capacities.
// 6. Add the bottleneck to the maximum flow.
// 7. Repeat steps 3–6 until BFS cannot find another augmenting path.
// 8. Print the maximum flow.


// Pseudocode
// EDMONDS-KARP(G, S, T):
//     maxFlow = 0
//     residual = capacity matrix

//     while BFS finds a path P from S to T:
//         bottleneck = infinity

//         for each edge (u, v) in P:
//             bottleneck = min(bottleneck, residual[u][v])

//         for each edge (u, v) in P:
//             residual[u][v] -= bottleneck
//             residual[v][u] += bottleneck

//         maxFlow += bottleneck

//     return maxFlow


// O(V.E2)