
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum number of multiplications: "
         << dp[1][n - 1] << '\n';

    return 0;
}


//Algorithm
// 1. Read the number of dimensions and the dimension array.
// 2. Initialize the DP table with zeros.
// 3. Consider matrix chains of increasing lengths.
// 4. For each chain, try every possible split position.
// 5. Calculate the cost of multiplying the left chain, right chain, and their resulting matrices.
// 6. Store the minimum cost in the DP table.
// 7. Print dp[1][n-1].
// 5. Pseudocode
// START
// Read n
// Read dimension array p[]

// Initialize dp[n][n] = 0

// FOR len = 2 TO n-1
//     FOR i = 1 TO n-len
//         j = i + len - 1
//         dp[i][j] = INFINITY

//         FOR k = i TO j-1
//             cost = dp[i][k] + dp[k+1][j]
//                    + p[i-1] * p[k] * p[j]

//             dp[i][j] = MIN(dp[i][j], cost)
//         END FOR
//     END FOR
// END FOR

// PRINT dp[1][n-1]
// STOP


// 6. Complexity
// - Time Complexity: O(n^3)
// - Space Complexity: O(n^2)