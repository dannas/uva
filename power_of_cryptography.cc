#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
    double n, p;

    while (cin >> n >> p)
        cout << (int)exp(log(p) / n) << "\n";
    return 0;
}
