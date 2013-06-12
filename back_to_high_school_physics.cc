#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int v;
    int t;

    // Acceleration is constant, the mean velocity will be after t/2
    while (cin >> v >> t)
        cout << 2 * v * t << "\n";
    return 0;
}
