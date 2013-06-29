// 483 - Word Scramble

// < I love you.
// < You love me.
// < We're a happy family.

// > I evol .uoy
// > uoY evol .em
// > er'eW a yppah .ylimaf

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
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
}
