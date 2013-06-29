// 10055 - Hashmat the brave warrior

// < 10 12
// < 10 14
// < 100 200

// > 2
// > 4
// > 100

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    long i, j;

    while (cin >> i >> j)
        cout << labs(i - j) << "\n";
}
