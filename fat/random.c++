
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S, R;
    cin >> N >> S;

    vector<int> status(N);

    for (int i = 0; i < N; i++)
        cin >> status[i];

    cin >> R;
    srand(R);

    int actualFailed = 0;

    for (int x : status)
        actualFailed += x;

    vector<int> ids(N);
    iota(ids.begin(), ids.end(), 0);
    random_shuffle(ids.begin(), ids.end());

    int sampleFailed = 0;

    cout << "=== Randomized Server Sampling ===\n";

    for (int i = 0; i < S; i++) {
        int id = ids[i];

        cout << "Server " << id + 1
             << ": " << (status[id] ? "Failed" : "Healthy") << '\n';

        sampleFailed += status[id];
    }

    double estimated = 100.0 * sampleFailed / S;
    double actual = 100.0 * actualFailed / N;

    cout << fixed << setprecision(2);
    cout << "Sample Failed Servers: " << sampleFailed << '\n';
    cout << "Estimated Failure Percentage: " << estimated << "%\n";
    cout << "Actual Failure Percentage: " << actual << "%\n";

    return 0;
}


// Algorithm
// 1. Read the total number of servers \(N\), sample size \(S\), server statuses, and random seed \(R\).
// 2. Count the actual failed servers in the supplied dataset.
// 3. Initialize server IDs from 0 to N-1.
// 4. Shuffle the IDs randomly using seed \(R\).
// 5. Select the first \(S\) servers and count their failures.
// 6. Estimate the failure percentage using
// 7. Calculate the actual failure percentage and print both values for comparison.
// 5. Pseudocode
// RANDOMIZED-SERVER-SAMPLING(N, S, status, R):

//     set random seed R
//     actualFailed = count of failed servers

//     ids = [0, 1, ..., N-1]
//     shuffle(ids)

//     sampleFailed = 0

//     for i = 0 to S-1:
//         sampleFailed += status[ids[i]]

//     estimated = sampleFailed / S * 100
//     actual = actualFailed / N * 100

//     print estimated and actual percentages


// 6. Complexity
// - Time: \(O(N)\) to count failures and shuffle IDs, plus \(O(S)\) to inspect the sample; overall \(O(N)\).
// - Space: \(O(N)\) for server statuses and shuffled IDs.