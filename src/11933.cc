#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int x;

    while (cin >> x && x != 0) {

        // Let 0 <= i1 < i2 < ... < ik be indices of 1-bits.
        int a = 0; // Then a is i1, i3, i5, ...
        int b = 0; // And b is  i2, i4, i6, ...

        bool even = true;

        for (unsigned mask = 1; mask < INT_MAX; mask <<= 1) {
            int bit = x & mask;
            if (bit) {
                if (even) {
                    a |= bit;
                } else {
                    b |= bit;
                }
                even = !even;
            }
        }
        cout << a << " " << b << "\n";
    }
}
