#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int main()
{
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        if (a[0] > a[1])
            swap(a, 0, 1);

        if (a[1] > a[2])
            swap(a, 1, 2);

        if (a[0] > a[2])
            swap(a, 0, 2);

        cout << "Case " << i << ": " << a[1] << "\n";
    }
}
