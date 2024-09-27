#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    
    int s=0, t=N-1;
    int min_value = 2'000'000'000;
    int index1, index2;

    while(s<t)
    {
        if (abs(vec[s]+vec[t])<min_value)
        {
            min_value = abs(vec[s]+vec[t]);
            index1 = s;
            index2 = t;
        }

        if (abs(vec[s+1]+vec[t]) < abs(vec[s]+vec[t-1]))
            s++;
        else
            t--;
    }
    
    cout << vec[index1] << ' ' << vec[index2] << endl;

    return 0;
}