
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, K;
    cin >> N >> T;

    vector<int> p(N), v(N), s(N);

    for (int i = 0; i < N; i++) cin >> p[i];
    for (int i = 0; i < N; i++) cin >> v[i];

    cin >> K;

    for (int i = 0; i < N; i++) cin >> s[i];

    int time = 0, value = 0;

    cout << "=== Certificate Verification ===\n";

    for (int i = 0; i < N; i++) {
        if (s[i] == 1) {
            time += p[i];
            value += v[i];
        }
    }

    bool timeOK = time <= T;
    bool valueOK = value >= K;

    cout << "Total Processing Time: " << time << '\n';
    cout << "Total Production Value: " << value << '\n';

    cout << "Time Constraint: "
         << (timeOK ? "Satisfied" : "Violated") << '\n';

    cout << "Value Constraint: "
         << (valueOK ? "Satisfied" : "Violated") << '\n';

    if (timeOK && valueOK)
        cout << "Certificate Verification: ACCEPTED\n";
    else
        cout << "Certificate Verification: REJECTED\n";

    return 0;
}


// Algorithm
// 1. Read the number of jobs \(N\), time limit \(T\), processing times, production values, minimum required value \(K\), and the certificate.
// 2. Initialize total processing time and production value to zero.
// 3. For each job selected in the certificate (s[i] == 1):
//    - Add its processing time to the total time.
//    - Add its production value to the total value.
// 4. Check whether total time is at most \(T\).
// 5. Check whether total value is at least \(K\).
// 6. If both constraints are satisfied, accept the certificate.
// 7. Otherwise, reject the certificate.
// 8. Print the totals and verification result.
// Pseudocode
// VERIFY-CERTIFICATE(N, T, K, p, v, s):

//     time = 0
//     value = 0

//     for i = 0 to N-1:
//         if s[i] == 1:
//             time = time + p[i]
//             value = value + v[i]

//     timeOK = (time <= T)
//     valueOK = (value >= K)

//     if timeOK AND valueOK:
//         return ACCEPTED
//     else:
//         return REJECTED


// Time and space complexity
// - Time complexity: \(O(N)\) — each job is checked once.
// - Space complexity: \(O(N)\) — three arrays store the job details and certificate.
// - Concept: Polynomial-time verification of a proposed solution (certificate).