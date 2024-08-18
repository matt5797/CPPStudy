#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string S, T;

    cin >> S >> T;

    while (S.size()<T.size())
    {
        if (T.back() == 'A')
            T.pop_back();
        else if (T.back()=='B')
        {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
        else
            break;
    }

    if (S==T)
        cout << 1;
    else
        cout << 0;
    
    return 0;
}