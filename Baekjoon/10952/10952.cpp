#include <iostream>

using namespace std;

int main()
{
    int A, B;

    while(true)
    {
        cin >> A >> B;
        if (A+B==0)
            break;
        else
            cout << A + B << endl;
    }

    return 0;
}