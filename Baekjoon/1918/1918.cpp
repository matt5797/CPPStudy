#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    string input;
    cin >> input;

    stack<char> st;
    string output;
    
    for (auto c : input)
    {
        if (isalnum(c)) {
            output += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        } else if (isOperator(c)) {
            while (!st.empty() && getPriority(st.top()) >= getPriority(c)) {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }

    cout << output << endl;

    return 0;
}