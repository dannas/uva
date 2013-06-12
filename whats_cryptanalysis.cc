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

int main(int argc, const char *argv[])
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

    return 0;
}
