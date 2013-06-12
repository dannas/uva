#include <iostream>

using namespace std;

bool odd(int p) { return p % 2 == 1; }

int f(int b, int p, int m)
{
    //cout << "f(" << b << ", " << p << ", " << m << ")\n";
    int t;
    if (p == 0)
        t = 1;
    else if (odd(p))
        t =  (b * f(b, p-1, m)) % m;
    else {
        t = f(b, p/2, m) % m;
        t = (t * t) % m;
    }
           
    //cout << t % m << "\n";
    return t % m;
}

int main(int argc, const char *argv[])
{
    int b, p, m;

    while (cin >> b >> p >> m) {
        cout << f(b, p, m) << "\n";
    }

    return 0;
}
