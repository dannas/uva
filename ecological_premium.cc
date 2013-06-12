#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
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
    return 0;
}
