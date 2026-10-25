
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int crossingSum(vector<int>& a, int low, int mid, int high) {
    int sum = 0, leftSum = INT_MIN;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(vector<int>& a, int low, int high) {
    if (low == high)
        return a[low];

    int mid = low + (high - low) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = crossingSum(a, low, mid, high);

    return max({left, right, cross});
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Maximum Subarray Sum: "
         << maxSubarray(a, 0, n - 1) << endl;

    return 0;
}




// Algorithm
// 1. Find the middle index of the array.
// 2. Recursively find the maximum subarray sum in the left half.
// 3. Recursively find the maximum subarray sum in the right half.
// 4. Find the maximum crossing sum by checking left suffixes and right prefixes.
// 5. Return the maximum of the left, right, and crossing sums.
// 5. Pseudocode
// MAX-SUBARRAY(A, low, high):
//     IF low == high:
//         RETURN A[low]

//     mid = (low + high) / 2

//     left = MAX-SUBARRAY(A, low, mid)
//     right = MAX-SUBARRAY(A, mid+1, high)
//     cross = CROSSING-SUM(A, low, mid, high)

//     RETURN MAX(left, right, cross)


// 6. Complexity
// - Time: O(n log n)
// - Space: O(log n)