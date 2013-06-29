// 11462 - Age Sort

// < 5
// < 3 4 2 1 5
// < 5
// < 2 3 2 3 1
// < 0

// > 1 2 3 4 5
// > 1 2 2 3 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    while (cin >> n && n != 0) {
        vector<int> ages;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ages.push_back(x);
        }
        sort(ages.begin(), ages.end());
        for (int i = 0; i < n; i++) {
            if (i == 0)
                cout << ages[i];
            else
                cout << " " << ages[i];
        }
        cout << "\n";
    }
}
