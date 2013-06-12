#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s, t;

    while (cin >> s >> t) {
        bool match = true;
        size_t j = 0;
        for (size_t i = 0; i < s.size(); i++) {
            while (j < t.size() && t[j] != s[i])
                j++;
            if (j >= t.size()) {
                match = false;
                break;
            }
            j++;
        }
        if (match)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
    return 0;
}
