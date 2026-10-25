
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "LCS Length: " << dp[m][n] << endl;

    return 0;
}



// Algorithm
// 1. Read the two strings.
// 2. Create a DP table of size (m+1) × (n+1) and initialize it with zeros.
// 3. Compare each character of both strings.
// 4. If characters match, add 1 to the diagonal value: dp[i-1][j-1] + 1.
// 5. If they don't match, take the maximum of the top and left values.
// 6. Print dp[m][n], the LCS length.
// 7. Pseudocode
// START
// Read strings a and b
// m = length(a)
// n = length(b)

// Initialize dp[m+1][n+1] = 0

// FOR i = 1 TO m
//     FOR j = 1 TO n
//         IF a[i-1] == b[j-1]
//             dp[i][j] = dp[i-1][j-1] + 1
//         ELSE
//             dp[i][j] = MAX(dp[i-1][j], dp[i][j-1])
//         END IF
//     END FOR
// END FOR

// PRINT dp[m][n]
// STOP


// 8. Complexity
// - Time Complexity: O(m × n)
// - Space Complexity: O(m × n)