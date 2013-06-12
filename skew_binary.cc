#include <iostream>
#include <algorithm>

#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
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
    return 0;
}
