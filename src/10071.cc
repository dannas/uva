// 10071 - Back to High School Physics

// < 0 0
// < 5 12

// > 0
// > 120

#include <iostream>

using namespace std;

int main()
{
    int v;
    int t;

    // Acceleration is constant, the mean velocity will be after t/2
    while (cin >> v >> t)
        cout << 2 * v * t << "\n";
}
