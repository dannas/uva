#include <set>
#include <iostream>

using namespace std;

set<int> primes;

bool isoddprime(int d)
{
    if (primes.find(d) != primes.end())
        return true;

    for (int i = 3; i < d; i += 2)
        if (d % i == 0)
            return false;

    primes.insert(d);
    return true;
}

bool odd(int d) { return d & 0x01; }

int main(int argc, const char *argv[])
{
    int n;

    while (cin >> n && n != 0) {
        int mid = odd(n/2) ? n/2 : n/2+1;

        for (int i = 3; i <= mid; i += 2) {
            if (isoddprime(i) && isoddprime(n-i)) {
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
    }
    return 0;
}
