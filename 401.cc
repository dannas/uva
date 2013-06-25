// 401 - Palindromes

// < NOTAPALINDROME 
// < ISAPALINILAPASI 
// < 2A3MEAS 
// < ATOYOTA
// < MAIAM
// < 123ESI
// < 123ES1
// < DEO3D
// < 9339
// < A
// < B
// < E
// < M
// < 1
// < 3
// < 2
// < 4

// > NOTAPALINDROME -- is not a palindrome.
// >
// > ISAPALINILAPASI -- is a regular palindrome.
// >
// > 2A3MEAS -- is a mirrored string.
// >
// > ATOYOTA -- is a mirrored palindrome.
// >
// > MAIAM -- is a mirrored palindrome.
// > 
// > 123ESI -- is not a palindrome.
// > 
// > 123ES1 -- is a mirrored string.
// > 
// > DEO3D -- is not a palindrome.
// > 
// > 9339 -- is a regular palindrome.
// > 
// > A -- is a mirrored palindrome.
// > 
// > B -- is a regular palindrome.
// > 
// > E -- is a regular palindrome.
// > 
// > M -- is a mirrored palindrome.
// > 
// > 1 -- is a mirrored palindrome.
// > 
// > 3 -- is a regular palindrome.
// > 
// > 2 -- is a regular palindrome.
// > 
// > 4 -- is a regular palindrome.
// > 


#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> mirror;

bool ispalindrome(const string &line)
{
    int N = line.size();

    for (int i = 0, j = N-1; i < j; i++, j--)
        if (line[i] != line[j])
            return false;
    return true;
}

bool ismirror(const string &line)
{
    int N = line.size();

    for (int i = 0, j = N-1; i <= j; i++, j--)
        if (line[i] != mirror[(int)line[j]])
            return false;
    return true;
}

int main()
{
    string line;

    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';

    while (getline(cin, line)) {
        cout << line;
        if (ispalindrome(line) && ismirror(line))
            cout << " -- is a mirrored palindrome.";
        else if (ismirror(line))
            cout << " -- is a mirrored string.";
        else if (ispalindrome(line))
            cout << " -- is a regular palindrome.";
        else
            cout << " -- is not a palindrome.";
        cout << "\n\n";
    }
}
