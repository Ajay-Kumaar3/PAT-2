
#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int id, start, finish;
};

int main() {
    vector<Activity> a = {
        {1,1,4}, {2,3,5}, {3,0,6}, {4,5,7},
        {5,3,9}, {6,5,9}, {7,6,10}, {8,8,11},
        {9,8,12}, {10,2,14}, {11,12,14}
    };

    sort(a.begin(), a.end(), [](Activity x, Activity y) {
        return x.finish < y.finish;
    });

    int last = 0;

    cout << "Selected Activities:\n";
    cout << "Activity " << a[0].id << " (" 
         << a[0].start << "-" << a[0].finish << ")\n";

    for (int j = 1; j < a.size(); j++) {
        if (a[j].start >= a[last].finish) {
            cout << "Activity " << a[j].id << " ("
                 << a[j].start << "-" << a[j].finish << ")\n";
            last = j;
        }
    }

    return 0;
}


// Algorithm
// 1. Store each activity's ID, start time, and finish time.
// 2. Sort all activities by increasing finish time.
// 3. Select the activity that finishes earliest.
// 4. Examine the remaining activities in sorted order.
// 5. Select an activity if its start time is greater than or equal to the finish time of the last selected activity.
// 6. Update the last selected activity.
// 7. Repeat until all activities have been examined.
// 8. Print the selected activities in execution order.


// 3. PSEDUCODE
// ACTIVITY-SELECTION(A):

//     Sort A by finish time
//     Select A[0]
//     last = 0

//     for j = 1 to N-1:
//         if A[j].start >= A[last].finish:
//             Select A[j]
//             last = j

//     return selected activities


// 4. Output
// Selected Activities (ordered by execution):
// Activity 1 (Start: 1, Finish: 4)
// Activity 4 (Start: 5, Finish: 7)
// Activity 11 (Start: 12, Finish: 14)


// 5. Time and space complexity
// - Time Complexity: \(O(N\log N)\) — sorting takes \(O(N\log N)\), and selecting activities takes \(O(N)\).
// - Space Complexity: \(O(N)\) for storing the activities.