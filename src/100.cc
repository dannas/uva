// 100 - The 3n + 1 problem

// < 1 10
// < 100 200
// < 201 210
// < 900 1000

// > 1 10 20
// > 100 200 125
// > 201 210 89
// > 900 1000 174

#include <iostream>
#include <climits>

using namespace std;

int cycle_length(int x)
{
    int n = 1;  // include printing of x

    while (x != 1) {
        if (x % 2 == 0)
            x = x / 2;
        else
            x = 3 * x +1;
        n++;
    }

    return n;
}

int calcmax(int i, int j)
{
    int m = INT_MIN;
    for (int k = min(i, j); k <= max(i, j); k++) {
        int n = cycle_length(k);
        if (n > m)
            m = n;
    }
    return m;
}

int main()
{
    int i, j;

    while (cin >> i >> j)
        cout << i << " " << j << " " << calcmax(i, j) << "\n";
}
