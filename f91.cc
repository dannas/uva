#include <iostream>
#include <map>

using namespace std;

map<int, int> memo;

int f91(int N)
{
    int x;

    if  (memo.find(N) != memo.end())
        return memo[N];

    if (N <= 100)
        x = f91(f91(N+11));
    else
        x = N-10;
    memo[N] = x;
    return x;
}


int main(int argc, const char *argv[])
{
    int N;

    while (cin >> N && N != 0)
        cout << "f91(" << N << ") = " << f91(N) << "\n";
    
    return 0;
}
