// 10264 - Problem B: The Most Potent Corner

// < 3
// < 82
// < 73
// < 8
// < 49
// < 120
// < 44
// < 242
// < 58
// < 2
// < 1
// < 1
// < 1
// < 1

// > 619
// > 4

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int dim;

    while (cin >> dim) {
        int N = pow(2, dim);

        vector<int> w(N); // weights of corners

        for (int i = 0; i < N; i++) {
            cin >> w[i];
        }

        vector<int> p(N); // potency of corners

        // Collect potency of each corner
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < dim; j++) {
                int b = i ^ (1 << j);
                sum += w[b];
            }
            p[i] = sum;
        }

        // Find neighbouring corners with highest potency
        int max_sum = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < dim; j++) {
                int b = i ^ (1 << j);
                max_sum = max(max_sum, p[i] + p[b]);
            }
        }
        cout << max_sum << "\n";
    }
}
