#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> items(N, {0,0}); // 무게, 가치
    for (int i = 0; i < N; i++)
        cin >> items[i].first >> items[i].second;
    
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int w = 0; w <= K; w++)
        {
            if (w>=items[i-1].first)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-items[i-1].first] + items[i-1].second);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}