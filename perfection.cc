#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
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
    return 0;

}
