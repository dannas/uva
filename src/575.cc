// 575 - Skew Binary

// < 10120
// < 200000000000000000000000000000
// < 10
// < 1000000000000000000000000000000
// < 11
// < 100
// < 11111000001110000101101102000
// < 0

// > 44
// > 2147483646
// > 3
// > 2147483647
// > 4
// > 7
// > 1041110737

#include <iostream>
#include <algorithm>

#include <cmath>

using namespace std;

int main()
{
    string line;

    while (getline(cin, line) && line != "0") {
        int dec = 0;
        reverse(line.begin(), line.end());

        for (unsigned i = 0; i < line.size(); i++) {
            int d = line[i] - '0';
            dec += d * (pow(2, i+1) -1);
        }
        cout << dec << "\n";
    }
}
