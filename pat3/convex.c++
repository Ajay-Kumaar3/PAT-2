
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int cross(Point a, Point b, Point c) {
    return (b.x-a.x)*(c.y-a.y) -
           (b.y-a.y)*(c.x-a.x);
}

double dist(Point a, Point b) {
    return hypot(a.x-b.x, a.y-b.y);
}

int main() {
    int n;
    cin >> n;
    vector<Point> p(n), h;

    for (auto &a : p) cin >> a.x >> a.y;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (p[i].y < p[l].y ||
           (p[i].y == p[l].y && p[i].x < p[l].x))
            l = i;

    int cur = l;
    do {
        h.push_back(p[cur]);
        int nxt = (cur+1)%n;

        for (int i = 0; i < n; i++) {
            int c = cross(p[cur], p[nxt], p[i]);
            if (c < 0 || (c == 0 &&
                dist(p[cur], p[i]) > dist(p[cur], p[nxt])))
                nxt = i;
        }

        cur = nxt;
    } while (cur != l);

    double perimeter = 0;
    for (int i = 0; i < h.size(); i++)
        perimeter += dist(h[i], h[(i+1)%h.size()]);

    cout << h.size() << '\n';
    for (auto a : h)
        cout << a.x << " " << a.y << '\n';

    cout << fixed << setprecision(2) << perimeter << '\n';
}

// Algorithm	      Time complexity
// Graham's Scan	    (O(Nlog N))
// Jarvis March	      (O(NH))


// Algorithm
// 1. Read the \(N\) points.
// 2. Find the starting point with the minimum \(y\)-coordinate. If tied, choose the minimum \(x\)-coordinate.
// 3. Add the starting point to the convex hull.
// 4. Select any other point as the next candidate.
// 5. Check every point using the cross product to find the next outermost point.
// 6. If points are collinear, choose the farthest point.
// 7. Repeat until the algorithm returns to the starting point.
// 8. Print the number of hull vertices and their coordinates in counter-clockwise order.
// 9. Calculate and print the perimeter by adding distances between consecutive hull vertices, including the last and first points.

// Pseudocode
// JARVIS-MARCH(P, N):
//     Find the lowest point (minimum y, then minimum x)
//     current = starting point
//     hull = empty list

//     do:
//         Add current to hull
//         next = any point other than current

//         for each point p in P:
//             if p is more counter-clockwise than next:
//                 next = p
//             else if p, current, next are collinear:
//                 next = farther point from current

//         current = next

//     while current != starting point

//     perimeter = 0
//     for i = 0 to hull.size - 1:
//         perimeter += distance(hull[i],
//                               hull[(i+1) % hull.size])

//     Print number of hull vertices
//     Print hull vertices
//     Print perimeter