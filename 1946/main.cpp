#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<pair<int, int>> v(N);

        for (int j = 0; j < N; j++)
        {
            cin >> v[j].first >> v[j].second;
        }

        sort(v.begin(), v.end());

        int cnt = 1;
        int highest = 0;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second < v[highest].second)
            {
                cnt++;
                highest = i;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}