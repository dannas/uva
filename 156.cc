// 156 - Ananagrams

// < ladder came tape soon leader acme RIDE lone Dreis peat
// <  ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
// < noel dire Disk mace Rob dries
// < #

// > Disk
// > NotE
// > derail
// > drIed
// > eye
// > ladder
// > soon

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

typedef multimap<string, string> Map;
typedef vector<string> Vector;

int main()
{
    string word;
    Map m;
    Vector v;
    Map::iterator i;
    Vector::iterator j;

    while (cin >> word && word != "#") {
        string key = word;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        sort(key.begin(), key.end());
        m.insert(make_pair(key, word));
    }

    for (i = m.begin(); i != m.end(); ++i)
        if (m.count(i->first) == 1)
            v.push_back(i->second);

    sort(v.begin(), v.end());

    for (j = v.begin(); j != v.end(); ++j)
        cout << *j << "\n";
}
