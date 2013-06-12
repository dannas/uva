#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[])
{
    long i, j;

    while (cin >> i >> j)
        cout << labs(i - j) << "\n";

    return 0;
}
