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

int main(int argc, const char *argv[])
{
    int i, j;

    while (cin >> i >> j)
        cout << i << " " << j << " " << calcmax(i, j) << "\n";
    return 0;
}
