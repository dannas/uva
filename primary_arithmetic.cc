#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    unsigned x, y;

    while (cin >> x >> y) {

        if (x == 0 && y == 0)
            return 0;

        int carry = 0;
        int carries = 0;

        while (x || y) {
            carry = (carry + (x % 10) + (y % 10)) / 10;
            x /= 10;
            y /= 10;
            if (carry)
                carries++;
        }

        if (carries == 1)
            cout << carries << " carry operation.\n";
        else if (carries)
            cout << carries << " carry operations.\n";
        else
            cout << "No carry operation.\n";
    }
    return 0;
}
