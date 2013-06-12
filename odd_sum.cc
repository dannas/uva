#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int ncases;
    cin >> ncases;
    for (int i = 0; i < ncases; i++) {
        int a, b, sum = 0;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (j % 2)
                sum += j;
        }
        cout << "Case " << i+1 << ": " << sum << "\n";
    }

    return 0;
}
