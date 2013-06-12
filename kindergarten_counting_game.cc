#include <iostream>

#include <cctype>

using namespace std;

int main(int argc, const char *argv[])
{
    string line;
    while (getline(cin, line)) {
        int n = 0;
        bool in_word = false;

        for (unsigned i = 0; i < line.size(); i++) {
            if (!in_word &&isalpha(line[i])) {
                in_word = true;
                n++;
            } else if (in_word && !isalpha(line[i]))
                in_word = false;
        }
        cout << n << "\n";
    }
    return 0;
}
