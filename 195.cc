// 195 - Anagram

// < 3
// < aAb
// < abc
// < acba

// > Aab
// > Aba
// > aAb
// > abA
// > bAa
// > baA
// > abc
// > acb
// > bac
// > bca
// > cab
// > cba
// > aabc
// > aacb
// > abac
// > abca
// > acab
// > acba
// > baac
// > baca
// > bcaa
// > caab
// > caba
// > cbaa

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

int main()
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
}
