#include <iostream>
#include <vector>
#include <sstream>

#include <climits>

using namespace std;

void exch(std::vector<int> &v, int i, int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

int main(int argc, const char *argv[])
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        int n;
        int x;
        vector<int> v;
        string line;
        int nswaps = 0;

        cin >> n;
        cin.ignore(INT_MAX, '\n');
        getline(cin, line);

        stringstream ss(line);

        while (ss >> x)
            v.push_back(x);

        for (int j = 0; j < n; j++) {
            for (int k = j; k > 0 && v[k] < v[k-1]; k--) {
                exch(v, k, k-1);
                nswaps++;
            }
        }
        cout << "Optimal train swapping takes " << nswaps << " swaps.\n";
    }
    return 0;
}
