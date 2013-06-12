#include <iostream>

using namespace std;

long long *a;
int inv = 0;

void count(int lo, int mid, int hi)
{
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mid)
            j++;
        else if (j > hi)
            i++;
        else if (a[i] <= a[j])
            i++;
        else {
            j++;
            inv++;
        }
    }
}

void sort(int lo, int hi)
{
    if (hi <= lo)
        return;

    int mid = lo + (hi-lo)/2;

    sort(lo, mid);
    sort(mid+1, hi);

    count(lo, mid, hi);
}

int main(int argc, const char *argv[])
{
    int N;
    cin >> N;
    a = new long long[N];

    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(0, N-1);

    cout << inv << "\n";

    return 0;
}
