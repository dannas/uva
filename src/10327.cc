// 10327 - Flip Sort

// < 3 
// < 1 2 3

// < 3
// < 2 3 1

// < 3
// < 3 2 1

// < 3
// < 1 3 2

// < 1
// < 1

// < 3
// < 2 1 3

// < 3
// < 3 1 2

// < 4
// < 4 3 2 1

// < 5
// < 5 1 3 5 1

// > Minimum exchange operations : 0
// > Minimum exchange operations : 2
// > Minimum exchange operations : 3
// > Minimum exchange operations : 1
// > Minimum exchange operations : 0
// > Minimum exchange operations : 1
// > Minimum exchange operations : 2
// > Minimum exchange operations : 6
// > Minimum exchange operations : 5

#include <iostream>

using namespace std;

long long a[1000];
int inv = 0;

int main()
{
    int N;
    while (cin >> N) {
        inv = 0;

        for (int i = 0; i < N; i++)
            cin >> a[i];

        // count flips
        for (int i = 0; i < N; i++)
            for (int j = i+1; j < N; j++)
                if (a[i] > a[j])
                    inv++;

        cout << "Minimum exchange operations : " << inv << "\n";
    }
}
