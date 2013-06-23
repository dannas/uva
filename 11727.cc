// 11727 - cost cutting

// < 3
// < 1000 2000 3000
// < 3000 2500 1500
// < 1500 1200 1800

// > Case 1: 2000
// > Case 2: 2500
// > Case 3: 1500

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());

        cout << "Case " << i << ": " << v[1] << "\n";
    }
}
