// 10008 - What's Cryptanalysis

// < 3
// < This is a test.
// < Count me 1 2 3 4 5.
// < Wow!!!!  Is this question easy?

// > S 7
// > T 6
// > I 5
// > E 4
// > O 3
// > A 2
// > H 2
// > N 2
// > U 2
// > W 2
// > C 1
// > M 1
// > Q 1
// > Y 1

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include <cctype>

using namespace std;

typedef pair<char, int> Nameval;

bool cmp(Nameval x, Nameval y)
{
    if (x.second > y.second) return true;
    if (x.second < y.second) return false;

    return x.first < y.first;
}

int main()
{
    char c;
    vector<Nameval> v;
    map<char, int> m;

    while (cin.get(c))
        if (isalpha(c))
            m[toupper(c)]++;

    copy(m.begin(), m.end(), back_inserter(v));
    sort(v.begin(), v.end(), cmp);

    vector<Nameval>::iterator i;
    for (i = v.begin(); i != v.end(); ++i)
        cout << i->first << " " << i->second << "\n";
}
