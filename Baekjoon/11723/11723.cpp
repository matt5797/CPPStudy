#include <iostream>

using namespace std;

enum operator_type
{
    _add,
    _remove,
    _check,
    _toggle,
    _all,
    _empty
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    unsigned int set = 0;

    for (int i=0; i<m; i++)
    {
        string op;
        unsigned int value=0;
        cin >> op;
        if (op!="all" && op!="empty")
            cin >> value;
        
        if (op=="add")
            set |= (1 << (value - 1));
        else if (op=="remove")
            set = (set | (1 << (value - 1))) ^ (1 << (value - 1)); 
        else if (op=="check") {
            if (set & (1 << (value - 1)))
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (op=="toggle")
            set ^= (1 << (value - 1));
        else if (op=="all")
            set = (1 << 20) - 1;
        else if (op=="empty")
            set = 0;
    }

    return 0;
}