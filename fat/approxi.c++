
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> sets(m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        while (k--) {
            int x;
            cin >> x;
            sets[i].push_back(x);
        }
    }

    vector<bool> covered(n + 1, false);
    vector<bool> used(m, false);

    int count = 0, totalCovered = 0;

    cout << "=== Greedy Set Cover Iterations ===\n";

    while (totalCovered < n) {
        int best = -1, bestCount = 0;

        for (int i = 0; i < m; i++) {
            if (used[i]) continue;

            int newCount = 0;

            for (int x : sets[i]) {
                if (!covered[x])
                    newCount++;
            }

            if (newCount > bestCount) {
                bestCount = newCount;
                best = i;
            }
        }

        if (best == -1) break;

        used[best] = true;
        count++;

        cout << "Iteration " << count << ": Selected S"
             << best + 1 << " = { ";

        for (int x : sets[best]) {
            cout << x << " ";

            if (!covered[x]) {
                covered[x] = true;
                totalCovered++;
            }
        }

        cout << "} | Total Covered = " << totalCovered << '\n';
    }

    if (totalCovered == n)
        cout << "Set Cover: COMPLETE\n";
    else
        cout << "Set Cover: INCOMPLETE\n";

    cout << "Number of Sets Selected: " << count << '\n';

    return 0;
}


// Algorithm
// 1. Read the universal set size and all available subsets.
// 2. Initialize all elements as uncovered.
// 3. Find the unused subset containing the most uncovered elements.
// 4. Select that subset and mark its elements as covered.
// 5. Repeat until all elements are covered or no useful subset remains.
// 6. Print the selected subsets and final result.


// Pseudocode
// GREEDY-SET-COVER(U, S):
//     covered = empty set
//     selected = empty list
//
//     while not all elements are covered:
//         choose unused subset with the most uncovered elements
//
//         if no useful subset exists:
//             break
//
//         select the subset
//         mark its elements as covered
//
//     return selected subsets and coverage status


// Time Complexity: O(n * m * L)
// Space Complexity: O(n + m + L)
//
// n = number of elements
// m = number of subsets
// L = total number of element occurrences
