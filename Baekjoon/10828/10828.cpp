#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N, x;
    string oper;
    stack<int> s;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> oper;
        if (oper == "push") {
            cin >> x;
            s.push(x);
        }
        else if (oper == "pop") {
            if (s.empty()) {
                cout << -1 << endl;
            } else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (oper == "size")
            cout << s.size() << endl;
        else if (oper == "empty")
            cout << (s.empty()? 1: 0) << endl;
        else if (oper == "top")
            cout << (s.empty()? -1: s.top()) << endl;
    }

    return 0;
}