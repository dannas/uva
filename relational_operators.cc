#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int N;
    cin >> N;

    while (N--) {
        long a, b;
        cin >> a >> b;

        if      (a < b)  cout << "<";
        else if (a == b) cout << "=";
        else             cout << ">";
        cout << "\n";
    }
    return 0;
}
