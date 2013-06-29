// 10370 - Above Average

// < 5
// < 5 50 50 70 80 100
// < 7 100 95 90 80 70 60 50
// < 3 70 90 80
// < 3 70 90 81
// < 9 100 99 98 97 96 95 94 93 91

// > 40.000%
// > 57.143%
// > 33.333%
// > 66.667%
// > 55.556%

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

#include <cstdio>
#include <climits>

using namespace std;

int main()
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        int N;
        vector<double> v;
        cin >> N;

        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        double avg = accumulate(v.begin(), v.end(), 0.0) / N;
        int above = count_if(v.begin(), v.end(),
                                bind2nd(greater<double>(), avg));
        
        printf("%.3f%%\n", (100.0 * above) / N);
    }
}
