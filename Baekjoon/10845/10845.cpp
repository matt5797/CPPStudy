#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, value;
    cin >> N;

    string oper;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        cin >> oper;
        if (oper == "push") {
            cin >> value;
            q.push(value);
        }
        else if (oper == "pop") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (oper == "size")
            cout << q.size() << endl;
        else if (oper == "empty") {
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (oper == "front") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
        else if (oper == "back") {
            if (q.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}