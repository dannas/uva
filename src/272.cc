// 272 - TeX Quotes

// < "To be or not to be," quoth the Bard, "that
// < is the question".
// < The programming contestant replied: "I must disagree.
// < To `C' or not to `C', that is The Question!"

// > ``To be or not to be,'' quoth the Bard, ``that
// > is the question''.
// > The programming contestant replied: ``I must disagree.
// > To `C' or not to `C', that is The Question!''

#include <iostream>

using namespace std;

int main()
{
    char c;
    bool backticks = true;

    while (cin.get(c)) {
        if (c == '"' && backticks) {
            cout << "``";
            backticks = false;
        } else if (c == '"') {
            cout << "''";
            backticks = true;
        } else {
            cout << c;
        }
    }
}
