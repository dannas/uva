#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>

#include <climits>
#include <cstdio>

using namespace std;

vector<int> in;
int N;

int last(const stack<int> &station)
{
    if (station.empty())
        return -1;
    return station.top();
}

bool shunt(vector<int> in, vector<int> order, int N)
{
    stack<int> station;
    int i = 0, j = 0;
    int k = 0;

    while (true) {
        if (k == N)
            return true;
        if (i == N && j == N)
            return false;

        printf("exp=%d station=%d in=%d\n", order[i], last(station), in[j]);

        if (last(station) == order[i]) {
            station.pop();
            k++;
        } else if (in[j] == order[i]) {
            j++;
            k++;
        } else if (j < N)  // coaches left on A
            station.push(in[j++]);
        i++;
    }
    return false;
}

int main(int argc, const char *argv[])
{
    int x;

    while (cin >> N && N != 0) {
        for (int i = 1; i <= N; i++) {
            in.push_back(i);
        }

        cin.ignore(INT_MAX, '\n');

        string s;

        while (getline(cin, s) && s != "0") {
            vector<int> out;
            stack<int> station;
            cout << "DANNAS " << s << endl;
            stringstream ss(s);

            for (int i = 0; i < N; i++) {
                ss >> x;
                out.push_back(x);
            }

            if (shunt(in, out, N))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
