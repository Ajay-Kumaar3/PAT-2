
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[2][100], t[2][100];
    int e1, e2, x1, x2;

    cin >> e1 >> e2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n - 1; j++)
            cin >> t[i][j];

    cin >> x1 >> x2;

    int dp1[100], dp2[100];

    dp1[0] = e1 + a[0][0];
    dp2[0] = e2 + a[1][0];

    for (int i = 1; i < n; i++) {
        dp1[i] = min(dp1[i - 1] + a[0][i],
                     dp2[i - 1] + t[1][i - 1] + a[0][i]);

        dp2[i] = min(dp2[i - 1] + a[1][i],
                     dp1[i - 1] + t[0][i - 1] + a[1][i]);
    }

    int ans = min(dp1[n - 1] + x1,
                  dp2[n - 1] + x2);

    cout << "Minimum time: " << ans << '\n';

    return 0;
}


// Algorithm
// 1. Read the number of stations, entry times, station processing times, transfer times, and exit times.
// 2. Initialize the minimum time to reach the first station on each line.
// 3. For every next station, calculate the minimum time for both lines:
//    - Stay on the same line.
//    - Transfer from the other line.
// 4. Choose the smaller time for each line.
// 5. Add each line's exit time and choose the smaller total.
// 6. Print the minimum total time.
// 5. Pseudocode
// Read n, entry times, station times, transfer times, exit times

// dp1[0] = entry1 + station1[0]
// dp2[0] = entry2 + station2[0]

// FOR i = 1 TO n-1:
//     dp1[i] = MIN(
//         dp1[i-1] + station1[i],
//         dp2[i-1] + transfer2[i-1] + station1[i]
//     )

//     dp2[i] = MIN(
//         dp2[i-1] + station2[i],
//         dp1[i-1] + transfer1[i-1] + station2[i]
//     )

// answer = MIN(dp1[n-1] + exit1,
//              dp2[n-1] + exit2)

// PRINT answer


// 6. Complexity
// - Time: \(O(n)\)
// - Space: \(O(n)\)