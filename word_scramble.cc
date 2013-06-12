#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        string w;
        vector<string> words;

        while (ss >> w)
            words.push_back(w);

        for (size_t i = 0; i < words.size(); i++) {
            w = words[i];
            reverse(w.begin(), w.end());
            if (i == 0)
                cout << w;
            else
                cout << " " << w;
        }
        cout << "\n";
    }

    return 0;
}
