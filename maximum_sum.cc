#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Rect
{
    Rect(int ycor0, int xcor0, int ycor1, int xcor1) :
            y0(ycor0), x0(xcor0), y1(ycor1), x1(xcor1) {}
    int y0;
    int x0;
    int y1;
    int x1;

    bool operator< (const Rect& rhs) const
    {
        if (y0 < rhs.y0 || x1 < rhs.x1)
            return true;
        return false;
    }
};

map<Rect, int> m;

int calc(int** a, Rect r)
{
    if (m.find(r) != m.end())
        return m[r];

    int x = 0;
    int mid = r.y0 + (r.y1 - r.y0) / 2;

    if (mid == r.y0) {
        for (int i = r.x0; i <= r.x1; i++)
            x += a[mid][i];
    }
    else
        x = calc(a, Rect(r.y0, r.x0, mid, r.x1)) +
            calc(a, Rect(r.y0, r.x0, mid+1, r.x1));
    m[r] = x;
    cout << x << "\n";

    return x;
}

int main(int argc, const char *argv[])
{
    int n;

    cin >> n;
    // TODO: Why did vector<vector<int> > not work?
    int **a = new int*[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    calc(a, Rect(i, j, k, l));
                }
            }
        }
    }
    return 0;
}
