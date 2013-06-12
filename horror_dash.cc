#include <iostream>
#include <sstream>
#include <vector>
#include <climits>


using namespace std;

int main(int argc, const char *argv[])
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
    return 0;
}
