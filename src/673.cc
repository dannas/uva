// 673 - Parentheses Balance

// < 3
// < ([])
// < (([()])))
// < ([()[]()])()

// > Yes
// > No
// > Yes

#include <iostream>
#include <stack>

using namespace std;

bool contains(stack<char> &stack, char c)
{
    bool found = !stack.empty() && stack.top() == c;
    if (found)
        stack.pop();
    return found;
}

int main()
{
    string line;
    getline(cin, line);     // ignore first line

    while (getline(cin, line)) {
        bool correct = true;
        stack<char> stack;

        for (size_t i = 0; correct && i < line.size(); i++) {
            char c = line[i];

            if      (c == '(' || c == '[')
                stack.push(c);
            else if (c == ')' && !contains(stack, '('))
                correct = false;
            else if (c == ']' && !contains(stack, '['))
                correct = false;
        }

        if (correct && stack.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
