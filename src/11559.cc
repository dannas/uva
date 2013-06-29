// 11559 - Event Planning

// < 3 1000 2 3
// < 200
// < 0 2 2
// < 300
// < 27 3 20
// < 5 2000 2 4
// < 300
// < 4 3 0 4
// < 450
// < 7 8 0 13

// > 900
// > stay home

#include <iostream>
#include <climits>

using namespace std;

int main()
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
}
