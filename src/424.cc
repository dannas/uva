// 424 - Integer inquiry

// < 123456789012345678901234567890
// < 123456789012345678901234567890
// < 123456789012345678901234567890
// < 0

// > 370370367037037036703703703670

#include <iostream>
#include <algorithm>

using namespace std;

typedef string Bigint;  // reversed string of non-negative number with each
                        // digit mapped to digit - '0'

Bigint add(Bigint x, Bigint y)
{
    int carry = 0;
    int z;
    unsigned N = max(x.size(), y.size());
    Bigint sum(N, '0');

    for (unsigned i = 0; i < N; i++) {
        if (i < x.size() && i < y.size())
            z = x[i] + y[i];
        else if (i < x.size())
            z = x[i];
        else
            z = y[i];
        sum[i] = (z + carry ) % 10;
        carry = (z + carry) / 10;
    }
    if (carry)
        sum.push_back(carry);

    return sum;
}

string to_string(Bigint x)
{
    int N = x.size();

    for (int i = 0; i < N; i++)
        x[i] = x[i] + '0';

    reverse(x.begin(), x.end());
    return x;
}

Bigint to_bigint(string s)
{
    int N = s.size();

    for (int i = 0; i < N; i++)
        s[i] = s[i] - '0';
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string line;
    Bigint sum;

    while (cin >> line && line != "0") {
        Bigint x = to_bigint(line);
        sum = add(sum, x);
    }
    cout << to_string(sum) << "\n";
}
