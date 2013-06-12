#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int n = 1;
    int i = 2;

    while (true) {
        int rem = i / 5;
        rem = rem / 3;
        rem = rem / 2;

        if (rem == 0)
            n++;

        if (n == 1500) {
            cout << i << "\n";
            return 0;
        }
        i++;
    }
    return 0;
}
