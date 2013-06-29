// 591 - Box of Bricks

// < 6
// < 5 2 4 1 7 5
// < 0

// > Set #1
// > The minimum number of moves is 5.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int nsets = 0;

    while (cin >> n) {
        if (n == 0)
            return 0;
        nsets++;

        vector<int> v;
        int sum = 0;
        int x;

        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            v.push_back(x);
        }
        int mean = sum / n;
        int moves = 0;

        cout << "Set #" << nsets << "\n";
        for (int i = 0; i < n; i++)
            if (v[i] < mean)
                moves += mean - v[i];

        cout << "The minimum number of moves is " << moves << ".\n\n";
    }
}
