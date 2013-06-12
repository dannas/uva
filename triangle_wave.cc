#include <iostream>

using namespace std;

void put(int c)
{
    for (int i = 0; i < c; i++)
        cout.put('0' + c);
    cout.put('\n');
}

int main(int argc, const char *argv[])
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
    return 0;
}
