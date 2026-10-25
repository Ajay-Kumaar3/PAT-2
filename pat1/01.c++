
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), profit(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][W] << endl;

    return 0;
}



// Algorithm
// 1. Read the number of items, bag capacity, weights, and profits.
// 2. Initialize a DP table with zeros.
// 3. For each item and capacity, first consider skipping the item.
// 4. If the item's weight fits, compare skipping it against selecting it.
// 5. Store the maximum profit in the DP table.
// 6. Print dp[n][W].
// 7. Pseudocode
// START
// Read n and W
// Read weight[] and profit[]

// Initialize dp[n+1][W+1] = 0

// FOR i = 1 TO n
//     FOR w = 0 TO W
//         dp[i][w] = dp[i-1][w]

//         IF weight[i-1] <= w
//             dp[i][w] = MAX(
//                 dp[i][w],
//                 profit[i-1] + dp[i-1][w-weight[i-1]]
//             )
//         END IF
//     END FOR
// END FOR

// PRINT dp[n][W]
// STOP


// 8. Complexity
// - Time Complexity: O(n × W)
// - Space Complexity: O(n × W)