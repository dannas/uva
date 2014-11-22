// 12356 - Army buddies

// < 1 1
// < 1 1
// < 10 4
// < 2 5
// < 6 9
// < 1 1
// < 10 10
// < 5 1
// < 1 1
// < 0 0

// > * *
// > -
// > 1 6
// > 1 10
// > * 10
// > * *
// > -
// > * 2
// > -

#include <cstdio>
#include <vector>

int S, B, L, R;

int left[1000000];
int right[1000000];

int main()
{
    while (true) {
        scanf("%d %d", &S, &B);
        if (S == 0 && B == 0)
            break;

        for (int i = 0; i <= S; i++) {
            left[i] = i-1;
            right[i] = i+1;
        }

        while (B--) {
            scanf("%d %d", &L, &R);
            if (left[L] < 1) printf("* ");
            else             printf("%d ", left[L]);

            if (right[R] > S) printf("*\n");
            else              printf("%d\n", right[R]);

            //    L   R
            // | |x|x|x | | |
            //  ^        ^
            // left[L]   |
            //          right[R]
            left[right[R]] = left[L];
            right[left[L]] = right[R];

        }
        printf("-\n");
    }
}
