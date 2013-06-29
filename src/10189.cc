// 10189 - Minesweeper

// < 4 4
// < *...
// < ....
// < .*..
// < ....
// < 3 5
// < **...
// < .....
// < .*...
// < 0 0

// > Field #1:
// > *100
// > 2210
// > 1*10
// > 1110
// > 
// > Field #2:
// > **100
// > 33200
// > 1*100

#include <iostream>

using namespace std;

int n, m;

bool mine(char **a, int row, int col)
{
    if (row < 0 || row >= n)
        return false;
    if (col < 0 || col >= m)
        return false;

    return a[row][col] == '*';
}

int neighbours(char **a, int row, int col)
{
    int n = 0;

    if (mine(a, row, col-1))
        n++;
    if (mine(a, row+1, col-1))
        n++;
    if (mine(a, row+1, col))
        n++;
    if (mine(a, row+1, col+1))
        n++;
    if (mine(a, row, col+1))
        n++;
    if (mine(a, row-1, col+1))
        n++;
    if (mine(a, row-1, col))
        n++;
    if (mine(a, row-1, col-1))
        n++;
    return n;
}

int main()
{
    int nfields = 1;
    while (cin >> n >> m) {

        if (n == 0 && m == 0)
            return 0;

        char **a = new char*[n];
        for (int i = 0; i < n; i++)
            a[i] = new char[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                a[i][j] = c;
            }
        }

        if (nfields > 1)
            cout << "\n";
        cout << "Field #" << nfields << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '*')
                    cout << '*';
                else {
                    char c = '0' + neighbours(a, i, j);
                    cout << c;
                }
            }
            cout << "\n";
        }
        nfields++;

        for (int i = 0; i < n; i++)
            delete[] a[i];
        delete[] a;
    }
}
