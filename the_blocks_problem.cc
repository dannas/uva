#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

#define NDEBUG
#include <assert.h>

using namespace std;

int N;

typedef list<int> Pile;

vector<Pile> piles;
map<int, int> blocktab;     // blockno -> pile

bool check()
{
    if ((unsigned)N != piles.size())
        return false;

    // All N blocks must be unique
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int j = 0; j < N; j++)
            x += count(piles[j].begin(), piles[j].end(), i);
        if (x != 1)
            return false;
    }

    // All N blocks must be a key in blocktab
    for (int i = 0; i < N; i++)
        if (blocktab.find(i) == blocktab.end())
            return false;

    // blocktab must point to the right pile
    std::map<int, int>::iterator i;
    for (i = blocktab.begin(); i != blocktab.end(); ++i) {
        Pile &p = piles[i->second];
        if (find(p.begin(), p.end(), i->first) == p.end())
            return false;
    }
    return true;
}

void do_move(Pile &dst, int b, Pile &src, Pile::iterator i)
{
    for (Pile::iterator j = i; j != src.end(); ++j)
        blocktab[*j] = blocktab[b];
    dst.splice(dst.end(), src, i, src.end());
}

// put blocks above block back to original pos.
void popto(Pile &p, int block)
{
    int x;
    while ((x = p.back()) != block) {
        p.pop_back();
        piles[x].push_back(x);
        blocktab[x] = x;
    }
}

void print()
{
    for (int i = 0; i < N; i++) {
        cout << i << ":";
        Pile &p = piles[i];
        for (Pile::iterator j = p.begin(); j != p.end(); ++j)
            cout << " " << *j;
        cout << "\n";
    }
}

// move block a to pile of b, removing blocks above b if onto and moving
// blocks above a too, if move_pile
void move(int a, int b, bool onto, bool move_pile)
{
    Pile &src = piles[blocktab[a]];
    Pile &dst = piles[blocktab[b]];
    if (onto)
        popto(dst, b);
    if (!move_pile)
        popto(src, a);
    do_move(dst, b, src, find(src.begin(), src.end(), a));

    assert(check());
}

void init()
{
    for (int i = 0; i < N; i++) {
        piles.push_back(Pile());
        piles[i].push_back(i);
        blocktab[i] = i;
    }
}

int main(int argc, const char *argv[])
{
    string cmd;
    int a, b;
    string pp;     // preposition

    cin >> N;

    init();

    while (cin >> cmd && cmd != "quit") {
        cin >> a >> pp >> b;

        if (a == b || blocktab[a] == blocktab[b])
            continue;   // ignore bad input

        if      (cmd == "move" && pp == "onto") move(a, b, true,  false);
        else if (cmd == "move" && pp == "over") move(a, b, false, false);
        else if (cmd == "pile" && pp == "onto") move(a, b, true,  true);
        else if (cmd == "pile" && pp == "over") move(a, b, false, true);
    }
    print();

    return 0;
}
