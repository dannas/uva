// 10696 - f91

// < 500
// < 91
// < 0

// > f91(500) = 490
// > f91(91) = 91

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

int main()
{
    int N;

    while (cin >> N && N != 0)
        cout << "f91(" << N << ") = " << f91(N) << "\n";
}
