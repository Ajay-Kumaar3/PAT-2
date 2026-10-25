#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10)
        return x * y;

    int n = max(to_string(x).size(), to_string(y).size());
    int m = n / 2;

    long long p = 1;
    for (int i = 0; i < m; i++)
        p *= 10;

    long long a = x / p;
    long long b = x % p;
    long long c = y / p;
    long long d = y % p;

    long long z0 = karatsuba(b, d);
    long long z2 = karatsuba(a, c);
    long long z1 = karatsuba(a + b, c + d) - z2 - z0;

    return z2 * p * p + z1 * p + z0;
}

int main() {
    long long x, y;
    cin >> x >> y;

    cout << "Product: " << karatsuba(x, y) << endl;

    return 0;
}



// Algorithm
// 1. Read two integers x and y.
// 2. If either number is a single digit, multiply directly.
// 3. Split both numbers into high and low parts.
// 4. Calculate three recursive products:
//    - z0 = b * d
//    - z2 = a * c
//    - z1 = (a + b) * (c + d) - z2 - z0
// 5. Combine the results using the place value.
// 6. Print the product.
// 5. Pseudocode
// KARATSUBA(x, y):
//     IF x < 10 OR y < 10:
//         RETURN x * y

//     n = maximum number of digits in x and y
//     m = floor(n / 2)
//     p = 10^m

//     a = x / p
//     b = x % p
//     c = y / p
//     d = y % p

//     z0 = KARATSUBA(b, d)
//     z2 = KARATSUBA(a, c)
//     z1 = KARATSUBA(a+b, c+d) - z2 - z0

//     RETURN z2*p*p + z1*p + z0


// 6. Complexity
// - Time: \(O(n^{1.585})\)