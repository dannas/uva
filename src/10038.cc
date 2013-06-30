// 10038 - Jolly jumpers

// < 4 1 4 2 3
// < 5 1 4 2 -1 6
// < 1 1
// < 2 1 1
// < 2 1 2
// < 2 1 3
// < 3 1 2 4

// > Jolly
// > Not jolly
// > Jolly
// > Not jolly
// > Jolly
// > Not jolly
// > Jolly

#include <iostream>
#include <cstdlib>

enum { SIZE = 3001 };

using namespace std;

int main()
{
    int N;

    while (cin >> N) {
        int a[SIZE], tbl[SIZE];

        for (int i = 0; i < N; i++)
            cin >> a[i];

        for (int i = 1; i < N; i++)
            tbl[i] = false;

        for (int i = 1; i < N; i++) {
            int diff = abs(a[i] - a[i-1]);
            if (diff > 0 && diff < N)
                tbl[diff] = true;
        }

        bool jolly = true;
        for (int i = 1; i < N; i++)
            if (tbl[i] == false)
                jolly = false;
        if (jolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}
