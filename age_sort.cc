#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
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
    return 0;
}
