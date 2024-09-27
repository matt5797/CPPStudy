#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    long long acc=0;
    cin >> N;

    vector<pair<long long, long long>> v(N);
    for (int i = 0; i<N; i++)
        cin >> v[i].first >> v[i].second;

    for (int i = 0; i<N; i++)
    {
        int j = (i + 1) % N;
        acc += v[i].first * v[j].second - v[j].first * v[i].second;
    }

    double result = abs(acc) / 2.0;
    
    printf("%.1f\n", result);

    return 0;
}