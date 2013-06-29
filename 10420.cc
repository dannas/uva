// 10420 - list of conquests

// < 3
// < Spain Donna Elvira
// < England Jane Doe
// < Spain Donna Anna

// > England 1
// > Spain 2

#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    string line;
    map<string, int> countries;

    getline(cin, line); // ignore # of lines

    while (getline(cin, line)) {
        string c;
        stringstream ss(line);

        ss >> c;
        countries[c] += 1;
    }

    map<string, int>::iterator i;

    for (i = countries.begin(); i != countries.end(); ++i)
        cout << i->first << " " << i->second << "\n";
}
