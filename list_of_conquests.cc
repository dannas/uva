#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[])
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
    
    return 0;
}
