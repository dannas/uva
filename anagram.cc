#include <iostream>
#include <algorithm>
#include <cmath>
#include <cctype>

using namespace std;

bool comp(char a, char b)
{
    bool same = abs(a - b) == 32;

    if (same)
        return a < b;
    return tolower(a) < tolower(b);
}

int main(int argc, const char *argv[])
{
    int unused;
    cin >> unused;

    string word;
    
    while (cin >> word) {
        sort(word.begin(), word.end(), comp);
        do {
            cout << word << "\n";
        } while (next_permutation(word.begin(), word.end()));
    }
    return 0;
}
