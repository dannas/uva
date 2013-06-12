#include <cstdio>
#include <cmath>

using namespace std;

const int DEG_PER_HOUR = 30;
const int DEG_PER_MIN = 6;

int main(int argc, const char *argv[])
{
    int hours, min;
    
    while ((scanf("%d:%d", &hours, &min)) == 2
           && hours != 0 && min != 0) {
        double hdeg = (hours  + min/60.0) * DEG_PER_HOUR;
        double mdeg = min * DEG_PER_MIN;

        double diff = fabs(hdeg - mdeg);
        printf("%.3f\n", diff > 180.0 ? 360.0-diff : diff);
    }
    return 0;
}
