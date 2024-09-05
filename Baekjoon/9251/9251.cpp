#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1, s2;
    int cnt = 0;

    cin >> s1 >> s2;
    
    vector<pair<int, int>> dp(s1.size() + 1, {0, 0});

    if (s1[0]==s2[0])
        dp[0] = {1, 0};

    for (int i=1; i<s1.length(); i++)
    {
        int max_value = 0;
        for (int j=0; j<i; j++)
        {
            if (dp[j].first+1<cnt)
                continue;

            int idx = s2.substr(dp[j].second, i-dp[j].second).find(s1[i]);
            cout << "j:" << j << " str:" << s2.substr(dp[j].second, i-dp[j].second) << " i:" << i << " c:" << s1[i] << " idx:" << idx << endl;
            if (idx != string::npos)
            {
                max_value = max(max_value, dp[j].first + 1);
                dp[i] = {max_value, dp[j].second + idx + 1};
                cnt = max_value;
                cout << "i:" << i << " max: " << max_value << " index: " << dp[j].second + idx << " s1:" << s1.substr(0, i) << " s2:" << s2.substr(0, i) << endl;
                break;
            }
        }
        if (dp[i].first==0)
        {
            dp[i] = dp[i-1];
            cout << "i:" << i << " max: " << dp[i].first << " index: " << dp[i].second << " s1:" << s1.substr(0, i) << " s2:" << s2.substr(0, i) << " x" << endl;
        }
    }

    cout << dp[dp.size()-1].first << endl;

    return 0;
}