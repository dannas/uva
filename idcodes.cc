#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string word;

    while (cin >> word && word != "#") {
        if (!next_permutation(word.begin(), word.end()))
            cout << "No successor\n";
        else
            cout << word << "\n";
    }
    return 0;
}
