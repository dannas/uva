// 11340 - Newspaper

// < 1
// < 7
// < a 3
// < W 10
// < A 100
// < , 10
// < k 7
// < . 3
// < I 13
// < 7
// < ACM International Collegiate Programming Contest (abbreviated
// < as ACM-ICPC or just ICPC) is an annual multi-tiered competition
// < among the universities of the world. The ICPC challenges students
// < to set ever higher standards of excellence for themselves
// < through competition that rewards team work, problem analysis,
// < and rapid software development.
// < From Wikipedia.

// > 3.74$

#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
    int N;

    cin >> N;

    while (N--) {
        int K;
        int sum = 0;
        map<char, int> costs;

        cin >> K;

        while (K--) {
            char c;
            int val;

            cin >> c >> val;
            costs[c] = val;
        }
        int nlines;
        string line;

        cin >> nlines;
        cin.ignore(256, '\n');

        while (nlines--) {
            getline(cin, line);

            for (size_t i = 0; i < line.size(); i++)
                sum += costs[(int)line[i]];
        }

        printf("%d.%02d$\n", sum / 100, sum % 100);
    }
}
