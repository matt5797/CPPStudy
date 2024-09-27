#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, T, P, size;
    int t=0;
    vector<int> tshirts(6);

    cin >> N;
    for (int i = 0; i < 6; i++)
        cin >> tshirts[i];
    cin >> T >> P;

    for (int size : tshirts)
    {
        t += (size / T);
        if (size % T != 0)
            t += 1;
    }
    
    cout << t << '\n' << N / P << ' ' << N % P << endl;

    return 0;
}