// 11498 - Division of Nlogonia

// < 3
// < 2 1
// < 10 10
// < -10 1
// < 0 33
// < 4
// < -1000 -1000
// < -1000 -1000
// < 0 0
// < -2000 -10000
// < -999 -1001
// < 0

// > NE
// > divisa
// > NO
// > divisa
// > NE
// > SO
// > SE

#include <iostream>

using namespace std;

int X, Y;

int border(int x, int y)    { return x == X || y == Y; }
int northwest(int x, int y) { return  x < X && y > Y; }
int northeast(int x, int y) { return x > X && y > Y; }
int southeast(int x, int y) { return x > X && y < Y; }
int southwest(int x, int y) { return x < X && y < Y; }

int main()
{
    int N, x, y;

    while (cin >> N && N != 0) {
        cin >> X >> Y;

        while (N--) {
            cin >> x >> y;

            if      (border(x, y))      cout << "divisa";
            else if (northwest(x, y))   cout << "NO";
            else if (northeast(x, y))   cout << "NE";
            else if (southeast(x, y))   cout << "SE";
            else if (southwest(x, y))   cout << "SO";
            cout << "\n";
        }
    }
}
