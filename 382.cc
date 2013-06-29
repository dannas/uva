// 382 - Perfection

// < 15 28 6 56 60000 22 496 0

// > PERFECTION OUTPUT
// >    15  DEFICIENT
// >    28  PERFECT
// >     6  PERFECT
// >    56  ABUNDANT
// > 60000  ABUNDANT
// >    22  DEFICIENT
// >   496  PERFECT
// > END OF OUTPUT

#include <cstdio>

using namespace std;

int main()
{
    int x;
    const char *label;

    printf("PERFECTION OUTPUT\n");
    while ((scanf("%d", &x) == 1) && x != 0) {
        int divsum = 0;
        for (int i = 1; i < x; i++)
            if (x % i == 0)
                divsum += i;

        if (divsum == x)
            label = "PERFECT";
        else if (divsum < x)
            label = "DEFICIENT";
        else
            label = "ABUNDANT";

        printf("%5d  %s\n", x, label);
    }
    printf("END OF OUTPUT\n");
}
