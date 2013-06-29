// 11172 - Relational operators

// < 3
// < 10 20
// < 20 10
// < 10 10

// > < 
// > > 
// > =

#include <iostream>

using namespace std;

int main()
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
}
