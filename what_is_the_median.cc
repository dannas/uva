#include <iostream>
#include <queue>
#include <functional>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > MinPq;
typedef priority_queue<int, vector<int>, less<int> > MaxPq;

// ### STL's pop() doesn't return the item.
template<typename T>
int pop(T &pq)
{
    int x = pq.top();
    pq.pop();
    return x;
}

int main(int argc, const char *argv[])
{
    int x;
    MaxPq lo;       // <= median
    MinPq hi;       // >= median

    while (cin >> x) {
        if (!hi.empty() && x < hi.top())
            lo.push(x);
        else
            hi.push(x);

        // rebalance
        if (lo.size() > hi.size() + 1)
            hi.push(pop(lo));
        else if (hi.size() > lo.size() + 1)
            lo.push(pop(hi));

        int m;
        if (lo.size() == hi.size())
            m = (lo.top() + hi.top()) / 2;
        else if (lo.size() < hi.size())
            m = hi.top();
        else
            m = lo.top();

        cout << m << "\n";
    }
    return 0;
}
