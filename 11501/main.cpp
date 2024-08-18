#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    
    cin >> t;

    for (int i=0 ;i<t; i++)
    {
        int n;
        cin >> n;
        
        vector<int> prices;
        for (int j=0; j<n; j++)
        {
            int price;
            cin >> price;
            prices.push_back(price);
        }

        long long max = 0;
        long long answer = 0;
        for (int j=prices.size()-1; j>=0; j--)
        {
            if (max < prices[j])
            {
                max = prices[j];
            }
            else
            {
                answer += max - prices[j];
            }
        }
        cout << answer << endl;
    }

    return 0;
}
