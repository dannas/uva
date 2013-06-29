// 488 - Triangle Wave

// < 1
// < 
// < 3
// < 2

// > 1
// > 22
// > 333
// > 22
// > 1
// > 
// > 1
// > 22
// > 333
// > 22
// > 1

#include <iostream>

using namespace std;

void put(int c)
{
    for (int i = 0; i < c; i++)
        cout.put('0' + c);
    cout.put('\n');
}

int main()
{
    int ncases;
    cin >> ncases;

    while (ncases--) {
        int amp, freq;
        cin >> amp >> freq;

        for (int i = 0; i < freq; i++) {
            for (int j = 1; j <=amp; j++)
                put(j);
            for (int j = amp-1; j > 0; j--)
                put(j);
            if (i != freq-1)
                cout << "\n";
        }
        if (ncases != 0)
            cout << "\n";
    }
}
