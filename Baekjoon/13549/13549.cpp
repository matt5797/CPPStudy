#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 100'000;

int main()
{
    int N, K;
    cin >> N >> K;

    int cnt = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<bool> visited(MAX_SIZE, false);

    q.push({0, N}); // 소요시간, 좌표
    
    while(!q.empty())
    {
        pair<int,int> n = q.top();
        q.pop();

        if (n.second==K)
        {
            cnt = n.first;
            break;
        }
        
        if (visited[n.second])
            continue;
        visited[n.second] = true;

        if (n.second < 100'000)
            q.push({n.first+1, n.second+1});
        if (n.second > 0)
            q.push({n.first+1, n.second-1});
        if (n.second <= 50'000)
            q.push({n.first, n.second*2});
    }

    cout << cnt << endl;

    return 0;
}