// 573 -  The Snail

// < 6 3 1 10
// < 10 2 1 50
// < 50 5 3 14
// < 50 6 4 1
// < 50 6 3 1
// < 1 1 1 1
// < 0 0 0 0

// > success on day 3
// > failure on day 4
// > failure on day 7
// > failure on day 68
// > success on day 20
// > failure on day 2

#include <iostream>

using namespace std;

bool doclimb(int *days, int height, double strides, double slides, int fatigue)
{
    double pos = 0.0;
    double loss = fatigue/100.0 * strides;
    *days = 1;

    while (true) {
        pos += strides;
        if (pos > height)
            return true;
        pos -= slides;

        if (pos < 0.0)
            return false;
        strides -= loss;
        if (strides < 0)
            strides = 0;
        *days += 1;
    }
    return pos >= height;
}

int main()
{
    int height;     // height of well
    int strides;    // dist climbed during day
    int slides;     // dist slided during night
    int fatigue;    // fatigue factor as percent

    while (cin >> height >> strides >> slides >> fatigue) {
        if (height == 0)
            return 0;
        int days;
        int ret = doclimb(&days, height, strides, slides, fatigue);

        cout << (ret ? "success" : "failure") << " on day " << days << "\n";

    }
}
