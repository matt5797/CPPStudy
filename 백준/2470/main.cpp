#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;
    
    vector<long long> vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int p1 = 0, p2 = N - 1;
    int res1 = p1, res2 = p2;
    long long min = abs(vec[0] + vec[N - 1]);

    while (p1 < p2-1)
    {
        if (abs(vec[p1+1] + vec[p2]) < abs(vec[p1] + vec[p2-1]))
        {
            if (abs(vec[p1+1] + vec[p2]) < min)
            {
                min = abs(vec[p1+1] + vec[p2]);
                res1 = p1 + 1;
                res2 = p2;
            }
            p1++;
        }
        else
        {
            if (abs(vec[p1] + vec[p2-1]) < min)
            {
                min = abs(vec[p1] + vec[p2-1]);
                res1 = p1;
                res2 = p2 - 1;
            }
            p2--;
        }
    }

    cout << vec[res1] << ' ' << vec[res2] << '\n';

    return 0;
}