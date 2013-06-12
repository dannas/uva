#include <iostream>
#include <vector>

#include <cstdlib>
#include <climits>

using namespace std;

vector<int> readints(int N)
{
    vector<int> v;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
    return v;
}

int main(int argc, const char *argv[])
{
    int ncases;
    cin >> ncases;

    while (ncases--) {
        int N;
        cin >> N;
        vector<int> v = readints(N);

        if (v.size() == 0)
            continue;

        int minsum = INT_MAX;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++)
                sum += abs(v[i] - v[j]);

            if (sum <= minsum)
                minsum = sum;
        }
        cout << minsum << "\n";
    }

    return 0;
}
