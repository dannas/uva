#include <iostream>
#include <sstream>

using namespace std;

bool is_palindrome(long x)
{
    stringstream ss;
    ss << x;
    string s = ss.str();
    unsigned n = s.size();

    for (unsigned i = 0, j = n-1; i < j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}

long reverse(long x)
{
    stringstream ss;
    ss << x;
    string s = ss.str();
    unsigned n = s.size();

    for (unsigned i = 0, j = n-1; i < j; i++, j--) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }

    ss.str(""); // TODO: Is this the best way to clear the stream?
    ss << s;
    ss >> x;
    return x;
}

int main(int argc, const char *argv[])
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        long p;
        int n = 0;
        cin >> p;

        while (!is_palindrome(p)) {
            int r = reverse(p);
            p = p + r;
            n++;
        }
        cout << n << " " << p << "\n";
    }
    return 0;
}
