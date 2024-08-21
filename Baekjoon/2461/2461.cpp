#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> classes;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        sort(temp.rbegin(), temp.rend());
        classes.push_back(temp);
    }

    int min_value = 1000000000;

    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({classes[i][0], {i, 0}});
        if (min_value > classes[i][0])
            min_value = classes[i][0];
    }

    int answer = 1000000000;
    while (true)
    {
        pair<int, pair<int, int>> max = pq.top();
        pq.pop();

        if (answer > max.first - min_value)
            answer = max.first - min_value;

        if (max.second.second == m-1)
            break;
        if (min_value > classes[max.second.first][max.second.second+1])
            min_value = classes[max.second.first][max.second.second+1];
        
        pq.push({classes[max.second.first][max.second.second+1], {max.second.first, max.second.second+1}});
    }

    cout << answer << endl;

    return 0;
}