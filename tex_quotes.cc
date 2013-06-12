#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
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
    return 0;
}
