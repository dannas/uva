#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

#define NELTS(v) ( sizeof(v) / sizeof(v[0]) )

using namespace std;

// shuffles             => vector of vector of int?
// applied shuffles     => int
// deck                 => vector of strings?
//
// applying a shuffle   => for each (i, j), swap(a, i, j)

void build(vector<string> &deck)
{
    string vals[] = {
        "2", "3", "4",
        "5", "6", "7",
        "8", "9", "10",
        "Jack", "Queen", "King", "Ace"
    };

    string suits[] = {
        "Clubs",
        "Diamonds",
        "Hearts",
        "Spades"
    };

    for (size_t i = 0; i < NELTS(suits); i++) {
        for (size_t j = 0; j < NELTS(vals); j++) {
            deck.push_back(vals[j] + " of " + suits[i]);
        }
    }
}

void exch(vector<string> &deck, int i, int j)
{
    string t = deck[i];
    deck[i] = deck[j];
    deck[j] = t;
}

void apply(vector<string> &deck, vector<int> &shuf)
{
    int N = shuf.size();
    for (int i = 0; i < N; i++) {
        exch(deck, i, shuf[i]);
    }
}

int main(int argc, const char *argv[])
{
    int ncases;
    string line;

    cin >> ncases;
    cin.ignore(INT_MAX, '\n');

    while (ncases--) {
        int nshuffles;
        vector<string> deck;
        vector<vector<int> > shuffles;

        build(deck);
        for (size_t i = 0; i < deck.size(); i++)
            cout << deck[i] << "\n";

        getline(cin, line);  // empty line
        cin >> nshuffles;
        cin.ignore(INT_MAX, '\n');

        for (int i = 0; i < nshuffles; i++) {
            vector<int> shuf;
            int x;
            for (int j = 0; j < 52; j++) {
                cin >> x;
                shuf.push_back(x-1);
            }
            shuffles.push_back(shuf);
        }
        cin.ignore(INT_MAX, '\n');

        while (getline(cin, line) && line != "") {
            int nshuf;
            stringstream ss(line);
            ss >> nshuf;
            apply(deck, shuffles[nshuf-1]);
        }

    }

    return 0;
}
