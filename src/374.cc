// 374 - Big Mod

// < 3
// < 18132
// < 17
// < 
// < 17
// < 1765
// < 3
// < 
// < 2374859
// < 3029382
// < 36123
// < 
// < 2
// < 2
// < 10

// > 13
// > 2
// > 13195
// > 4

#include <iostream>

using namespace std;

bool odd(int p) { return p % 2 == 1; }

int sq(int base, int exp, int mod)
{
    if (exp == 0)
        return 1;
    if (odd(exp))
        return base % mod * sq(base % mod, exp-1, mod) % mod;
    else {
        int t = sq(base % mod, exp/2, mod) % mod;
        return (t * t) % mod;
    }
}

int main()
{
    int base, exp, mod;

    while (cin >> base >> exp >> mod) {
        cout << sq(base, exp, mod) << "\n";
    }
}
