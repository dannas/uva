// 10855 - Rotated squares

// < 4 2
// < ABBA
// < ABBB
// < BAAA
// < BABB
// < AB
// < BB
// < 6 2
// < ABCDCD
// < BCDCBD
// < BACDDC
// < DCBDCA
// < DCBABD
// < ABCDBA
// < BC
// < CD
// < 0 0

// > 0 1 0 0
// > 1 0 1 0

#include <iostream>
#include <vector>

using namespace std;

using Row = vector<char>;
using Matrix = vector<Row>;

Matrix build(istream &in, int N)
{
    Matrix m(N, Row(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            in >> m[i][j];

    return m;
}

ostream& operator<<(ostream &os, Matrix &m)
{
    int N = m.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            os << m[i][j];
        os << "\n";
    }
    return os;
}

// TODO(dannas): How rotate in-place?
Matrix rotate(Matrix &m)
{
    int N = m.size();

    Matrix copy(N, Row(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copy[j][N-i-1] = m[i][j];
        }
    }

    return copy;
}

bool ismatch(Matrix &outer, Matrix &inner, int x, int y, int n)
{
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (inner[i-x][j-y] != outer[i][j])
                return false;
        }
    }
    return true;
}

int count_matches(Matrix &outer, Matrix &inner, int N, int n)
{
    int nmatches = 0;

    for (int i = 0; i < N-n+1; i++) {
        for (int j = 0; j < N-n+1; j++) {
            if (ismatch(outer, inner, i, j, n))
                nmatches++;
        }
    }
    return nmatches;
}

int main()
{
    int N; // dim of outer square
    int n; // dim of inner square

    while (cin >> N >> n) {

        if (N == 0 && n == 0)
            break;

        Matrix outer = build(cin, N);
        Matrix inner = build(cin, n);

        int x[4];
        for (int i = 0; i < 4; i++) {
            x[i] = count_matches(outer, inner, N, n);
            inner = rotate(inner);
        }
        cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
    }
}
