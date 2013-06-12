#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

#include <cstdio>
#include <climits>

using namespace std;

int main(int argc, const char *argv[])
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

    return 0;
}
