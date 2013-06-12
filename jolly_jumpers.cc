#include <iostream>
#include <vector>
#include <sstream>

#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[])
{
    string line; 

    while (getline(cin, line)) {
        int n, x;
        vector<int> v;
        stringstream ss(line);
        ss >> n;

        while (ss >> x)
            v.push_back(x);

        bool tbl[n];

        for (int i = 0; i < n; i++)
            tbl[i] = false;

        for (int i = 1; i < n; i++) {
            int diff = abs(v[i] - v[i-1]);
            if (diff > 0 && diff < n)
                tbl[diff] = true;
        }

        bool jolly = true;
        for (int i = 1; i < n; i++)
            if (tbl[i] == false)
                jolly = false;
        if (jolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
    return 0;
}
