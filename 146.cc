// 146 - ID Codes

// < abaacb
// < cbbaa
// < ab
// < ba
// < a
// < abc
// < acb
// < bac
// < cab
// < cba
// < #

// > ababac
// > No Successor
// > ba
// > No Successor
// > No Successor
// > acb
// > bac
// > bca
// > cba
// > No Successor

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string word;

    while (cin >> word && word != "#") {
        if (!next_permutation(word.begin(), word.end()))
            cout << "No Successor\n";
        else
            cout << word << "\n";
    }
    return 0;
}
