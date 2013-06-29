// 369 - Combinations

// < 100  6
// < 20  5
// < 18  6
// <  0  0

// > 100 things taken 6 at a time is 1192052400 exactly.
// > 20 things taken 5 at a time is 15504 exactly.
// > 18 things taken 6 at a time is 18564 exactly.

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int main()
{
    int N, M;

    while (cin >> N >> M && (N != 0 && M != 0)) {
        vector<int> e;      // enumerator "upper"
        vector<int> d;      // denominator

        for (int i = N-M+1; i <= N; i++) // N!/(N-M)! cancelled
            e.push_back(i);
        for (int i = 1; i <= M; i++)
            d.push_back(i);

        // cancel as much as possible
        for (int i = N; i >= 2; i--) {
            unsigned j = 0, k = 0;
            while (true) {
                while (j < e.size() && e[j] % i != 0)
                    j++;
                if (j >= e.size())
                    break;
                while (k < d.size() && d[k] % i != 0)
                    k++;
                if (k >= d.size())
                    break;
                e[j] = e[j] / i;
                d[k] = d[k] / i;
            }
        }

        long eprod = accumulate(e.begin(), e.end(), 1, multiplies<long>());
        long dprod = accumulate(d.begin(), d.end(), 1, multiplies<long>());
        long C = eprod / dprod;

        cout << N << " things taken " << M << " at a time is " << C
                << " exactly.\n";
    }
}
