// 11799 - horror dash

// < 2
// < 5 9 3 5 2 6
// < 1 2

// > Case 1: 9
// > Case 2: 2

#include <iostream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N;

    cin >> N;
    cin.ignore(INT_MAX, '\n');

    for (int i = 1; i <= N; i++) {
        string line;
        vector<int> v;
        int x, min = INT_MIN;

        getline(cin, line);
        stringstream ss(line);

        ss >> x;    // ignore # of scary clown

        while (ss >> x) {
            if (x > min)
                min = x;
        }
        cout << "Case " << i << ": " << min << "\n";
    }
}
