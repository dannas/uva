#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
#if 0
    string line;

    while (getline(cin, line)) {
        int points = 0;
        int extras = 0;
        string clubs, diamonds, spades, hearts;

        for (int i = 0; i < 7; i++) {
            if (line[i] == 'C')
                clubs += line[i+1];
            else if (line[i] == 'D')
                diamonds += line[i+1];
            else if (line[i] == 'H')
                hearts += line[i+1];
            else
                spades += line[i+1];
        }

        // rule 1
        if      (suit == 'A')   points += 4;
        else if (suit == 'K')   points += 3;
        else if (suit == 'Q')   points += 2;
        else if (suit == 'J')   points += 1;

        // rule 2
        // TODO: add more cases
        int n = count(clubs.begin(), clubs.end(), 'K');
        if (clubs.size() == n)
            points--;

        // rule 3
        // TODO: add more cases
        n = count(clubs.begin(), clubs.end(), 'Q');
        if (clubs.size() <= n + 1)
            points--;

        // rule 4
        // TODO: add more cases
        n = count(clubs.begin(), clubs.end(), 'J');
        if (clubs.size() <= n + 2)
            points--;
    }
#endif

    return 0;
}
