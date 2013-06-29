// 494 -  Kindergarten Counting Game

// < Meep Meep!
// < I tot I taw a putty tat.
// < I did! I did! I did taw a putty tat.
// < Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

// > 2
// > 7
// > 10
// > 9

#include <iostream>
#include <cctype>

using namespace std;

int main()
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
}
