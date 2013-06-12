#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, const char *argv[])
{
    char c;

    while (cin.get(c)) {
        if (isprint(c)) {
            if (c-7 < 32)   // wrap around
                cout.put(127 - 32 + c - 7);
            else
                cout.put(c-7);
        } else if (c == '\n')
            cout.put(c);
    }
    return 0;
}
