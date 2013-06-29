
// 11286 - Conformity

// < 3
// < 100 101 102 103 488
// < 100 200 300 101 102
// < 103 102 101 488 100
// < 3
// < 200 202 204 206 208
// < 123 234 345 456 321
// < 100 200 300 400 444
// < 0

// > 2
// > 3


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> Combination;

int main()
{
    int N;

    while (cin >> N && N != 0) {
        map<Combination, int> m;

        while (N--) {
            Combination c(5);

            cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4];
            sort(c.begin(), c.end());
            m[c]++;
        }

        int maxval = 0, nvals = 0;
        map<Combination, int>::iterator i;
        
        for (i = m.begin(); i != m.end(); ++i) {
            if (i->second == maxval) {
                nvals += i->second;
            } else if (i->second > maxval) {
                maxval = i->second;
                nvals = i->second;
            }
        }
        cout << nvals << "\n";
    }
}
