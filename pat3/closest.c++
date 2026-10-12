
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return hypot(a.x-b.x, a.y-b.y);
}

double solve(vector<Point>& p, int l, int r, Point &a, Point &b) {
    if (r-l <= 3) {
        double d = 1e18;
        for (int i=l; i<r; i++)
            for (int j=i+1; j<r; j++)
                if (dist(p[i],p[j]) < d) {
                    d = dist(p[i],p[j]);
                    a = p[i]; b = p[j];
                }
        return d;
    }

    int m = (l+r)/2;
    Point x1, y1, x2, y2;
    double d1 = solve(p,l,m,x1,y1);
    double d2 = solve(p,m,r,x2,y2);
    double d = d1;
    a=x1; b=y1;

    if (d2 < d) {
        d=d2; a=x2; b=y2;
    }

    vector<Point> s;
    for (int i=l; i<r; i++)
        if (abs(p[i].x-p[m].x) < d)
            s.push_back(p[i]);

    sort(s.begin(),s.end(),[](Point a,Point b) {
        return a.y < b.y;
    });

    for (int i=0; i<s.size(); i++)
        for (int j=i+1; j<s.size() && s[j].y-s[i].y<d; j++)
            if (dist(s[i],s[j]) < d) {
                d=dist(s[i],s[j]);
                a=s[i]; b=s[j];
            }

    return d;
}

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);

    for (auto &a:p) cin >> a.x >> a.y;

    sort(p.begin(),p.end(),[](Point a,Point b) {
        return a.x < b.x;
    });

    Point a, b;
    double d = solve(p,0,n,a,b);

    cout << fixed << setprecision(4) << d << '\n';
    cout << "(" << a.x << ", " << a.y << ") and ("
         << b.x << ", " << b.y << ")\n";
}


// Algorithm
// 1. Read \(N\) points.
// 2. Sort the points by their \(x\)-coordinates.
// 3. Divide the points into two halves.
// 4. Recursively find the closest pair in the left half and right half.
// 5. Take the smaller of the two minimum distances.
// 6. Create a strip containing points whose horizontal distance from the dividing line is less than the current minimum distance.
// 7. Sort the strip by \(y\)-coordinates and check nearby points to find a closer pair across the halves.
// 8. Update the minimum distance and corresponding coordinates.
// 9. Print the minimum distance rounded to four decimal places and the two points.


// Pseudocode
// CLOSEST-PAIR(P, l, r):
//     if number of points <= 3:
//         Find the closest pair by checking all pairs
//         Return minimum distance and pair

//     mid = (l + r) / 2

//     (d1, pair1) = CLOSEST-PAIR(P, l, mid)
//     (d2, pair2) = CLOSEST-PAIR(P, mid, r)

//     d = min(d1, d2)
//     bestPair = pair with distance d

//     Create strip of points within distance d
//     from the dividing line
//     Sort strip by y-coordinate

//     for each point in strip:
//         Check following points while y-distance < d
//         If a closer pair is found:
//             Update d and bestPair

//     Return d and bestPair


// MAIN:
//     Read N points
//     Sort points by x-coordinate
//     Find closest pair using CLOSEST-PAIR
//     Print minimum distance and both points



// TC - O(NlogN)