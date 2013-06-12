#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int bins[3][3];
map<char, int> cm;          // map color to index

int move(int bin, char c)
{
    int n = 0;
    int color = cm[c];

    for (int i = 0; i < 3; i++)
        if (i != bin)
            n += bins[i][color];

    return n;
}

// Find smallest val and resolve ties by comparing the keys
// lexiographically.
string min(map<string, int> &m)
{
    string order = m.begin()->first;
    int min = m.begin()->second;
    map<string, int>::iterator it;

    for (it = m.begin(); it != m.end(); ++it) {
        if (it->second == min && it->first < order)
            order = it->first;
        else if (it->second < min) {
            order = it->first;
            min = it->second;
        }
    }
    return order;
}

int main(int argc, const char *argv[])
{
    cm['B'] = 0;            // Brown
    cm['G'] = 1;            // Green
    cm['C'] = 2;            // Clear

    while (cin >> bins[0][0] >> bins[0][1] >> bins[0][2]
               >> bins[1][0] >> bins[1][1] >> bins[1][2]
               >> bins[2][0] >> bins[2][1] >> bins[2][2]) {

        string s = "BCG";       // alphabetical order
        map<string, int> m;

        do {
            m[s] = move(0, s[0]) + move(1, s[1]) + move(2, s[2]);
        } while (next_permutation(s.begin(), s.end()));

        string order = min(m);
        cout << order << " " << m[order] << "\n";
    }

    return 0;
}
