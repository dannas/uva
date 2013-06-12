#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

typedef map<char, int> Chartab;
typedef pair<char, int> Nameval;

void build(string &line, Chartab &tab)
{
    for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];
        if (isalpha(c))
            tab[c]++;
    }
}

bool cmp(Nameval x, Nameval y) { return x.second < y.second; }

int max(Chartab &t)
{
    Chartab::iterator i = max_element(t.begin(), t.end(), cmp);

    if (i == t.end())
        return -1;
    return i->second;
}

int main(int argc, const char *argv[])
{
    string line;

    while (getline(cin, line)) {
        Chartab tab;
        Chartab::iterator i;

        build(line, tab);

        int freq = max(tab);

        for (i = tab.begin(); i != tab.end(); ++i)
            if (i->second == freq)
                cout << i->first;

        // Assume line.size() > 0
        cout << " " << freq << "\n";
    }

    return 0;
}
