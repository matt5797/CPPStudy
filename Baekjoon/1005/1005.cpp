#include <iostream>
#include <vector>

using namespace std;

vector<int> D;
vector<int> dp;
vector<vector<int>> requires;

int getDP(int n)
{
    int max_time = 0;
    for (int node: requires[n])
    {
        if (dp[node]<0)
        {
            getDP(node);
        }
        max_time = max(max_time, dp[node]);
    }
    dp[n] = D[n] + max_time;
    return dp[n];
}

int main()
{
    int T, N, K;
    cin >> T;

    vector<int> results(T);
    for (int t = 0; t < T; t++)
    {
        cin >> N >> K;

        D.clear();
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            D.push_back(temp);
        }

        vector<pair<int, int>> edges(K);
        for (int i = 0; i < K; i++)
            cin >> edges[i].first >> edges[i].second;
        
        int W;
        cin >> W;
        
        requires.clear();
        for (int i = 0; i < N; i++)
        {
            vector<int> require;
            for (int j = 0; j < K; j++)
                if (edges[j].second == i+1)
                    require.push_back(edges[j].first-1);
            requires.push_back(require);
        }
        
        dp.clear();
        for (int i=0; i<N; i++)
            dp.push_back(-1);
        
        results[t] = getDP(W-1);
    }

    for (int result : results)
        cout << result << endl;

    return 0;
}