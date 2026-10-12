
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

struct Segment
{
    Point a, b;
};

int orient(Point a, Point b, Point c)
{
    double v = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (abs(v) < 1e-9)
        return 0;
    return v > 0 ? 1 : 2;
}

bool onSegment(Point a, Point b, Point c)
{
    return b.x >= min(a.x, c.x) - 1e-9 &&
           b.x <= max(a.x, c.x) + 1e-9 &&
           b.y >= min(a.y, c.y) - 1e-9 &&
           b.y <= max(a.y, c.y) + 1e-9;
}

bool intersect(Segment s, Segment t)
{
    int a = orient(s.a, s.b, t.a), b = orient(s.a, s.b, t.b);
    int c = orient(t.a, t.b, s.a), d = orient(t.a, t.b, s.b);

    if (a != b && c != d)
        return true;
    if (!a && onSegment(s.a, t.a, s.b))
        return true;
    if (!b && onSegment(s.a, t.b, s.b))
        return true;
    if (!c && onSegment(t.a, s.a, t.b))
        return true;
    if (!d && onSegment(t.a, s.b, t.b))
        return true;
    return false;
}

Point intersectionPoint(Segment s, Segment t)
{
    double a = s.b.y - s.a.y, b = s.a.x - s.b.x;
    double c = a * s.a.x + b * s.a.y;
    double d = t.b.y - t.a.y, e = t.a.x - t.b.x;
    double f = d * t.a.x + e * t.a.y;
    double det = a * e - d * b;

    if (abs(det) < 1e-9)
    {
        if (onSegment(s.a, t.a, s.b))
            return t.a;
        if (onSegment(s.a, t.b, s.b))
            return t.b;
        if (onSegment(t.a, s.a, t.b))
            return s.a;
        return s.b;
    }

    return {(e * c - b * f) / det, (a * f - d * c) / det};
}

int main()
{
    int n;
    cin >> n;
    vector<Segment> s(n);

    for (auto &x : s)
        cin >> x.a.x >> x.a.y >> x.b.x >> x.b.y;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (intersect(s[i], s[j]))
            {
                Point p = intersectionPoint(s[i], s[j]);
                cout << "COLLISION DETECTED\n";
                cout << fixed << setprecision(2) << p.x << " " << p.y << "\n";
                return 0;
            }

    cout << "CLEAR\n";
}

// 1. Algorithm
// 1. Read \(n\) line segments.
// 2. Compare each segment with every other segment.
// 3. Use the orientation test to determine whether two segments intersect.
// 4. Handle collinear segments by checking whether an endpoint lies on the other segment.
// 5. If an intersection is found, calculate and print the intersection point, then stop.
// 6. If no pair intersects, print CLEAR.

// 2. Pseudocode
// LINE-SEGMENT-INTERSECTION(S, n):
//     for i = 0 to n-1:
//         for j = i+1 to n-1:
//             if INTERSECT(S[i], S[j]):
//                 P = FIND-INTERSECTION-POINT(S[i], S[j])
//                 print "COLLISION DETECTED"
//                 print P
//                 return

//     print "CLEAR"

// INTERSECT(s1, s2):
//     Find orientations o1, o2, o3, o4

//     if o1 != o2 AND o3 != o4:
//         return TRUE

//     if o1 == 0 AND endpoint lies on s1:
//         return TRUE
//     if o2 == 0 AND endpoint lies on s1:
//         return TRUE
//     if o3 == 0 AND endpoint lies on s2:
//         return TRUE
//     if o4 == 0 AND endpoint lies on s2:
//         return TRUE

//     return FALSE

// TIME COMPLEXITY - O(n2)