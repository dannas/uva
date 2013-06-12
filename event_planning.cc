#include <iostream>
#include <climits>

using namespace std;

int main(int argc, const char *argv[])
{
    int np, budget, nhotels, nweeks;

    while (cin >> np >> budget >> nhotels >> nweeks) {
        int minprice = INT_MAX;

        for (int i = 0; i < nhotels; i++) {
            int price, beds;
            cin >> price;
            for (int j = 0; j < nweeks; j++) {
                cin >> beds;
                if (beds >= np && price * np < minprice)
                    minprice = price * np;
            }
        }
        if (minprice > budget)
            cout << "stay home\n";
        else
            cout << minprice << "\n";
    }

    return 0;
}
