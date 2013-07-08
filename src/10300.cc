// 10300 - Ecological premium

// < 3
// < 5
// < 1 1 1
// < 2 2 2
// < 3 3 3
// < 2 3 4
// < 8 9 2
// < 3
// < 9 1 8
// < 6 12 1
// < 8 1 1
// < 3
// < 10 30 40
// < 9 8 5
// < 100 1000 70

// > 38
// > 86
// > 7445

#include <iostream>

using namespace std;

int main()
{
    int n;                      // # of testcases
    cin >> n;

    for (int i = 0; i < n; i++) {
        int burden = 0;         // total cost for state
        int nf;                 // # of farmes

        cin >> nf;
        for (int j = 0; j < nf; j++) {
            int size;       // m2 land
            int na;         // # of animals
            int ef;         // enviroment friendliness

            cin >> size >> na >> ef;
            burden += (size * ef);
        }
        cout << burden << "\n";
    }
}
