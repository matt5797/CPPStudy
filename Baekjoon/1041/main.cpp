#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> p2 = {{0,1}, {0,2}, {0,3}, {0,4}, {5,1}, {5,2}, {5,3}, {5,4}, {1,2}, {1,3}, {2,4}, {3,4}};
    vector<vector<int>> p3 = {{0,1,2}, {0,1,3}, {0,2,4}, {0,3,4}, {5,1,2}, {5,1,3}, {5,2,4}, {5,3,4}};

    unsigned long long n, t;
    unsigned long long answer=0;
    vector<unsigned long long> dice;
    vector<unsigned long long> c2, c3;

    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> t;
        dice.push_back(t);
    }
    
    if (n==1)
    {
        int max = 0;
        for (int i = 0; i < 6; i++)
        {
            if (dice[i] > max)
                max = dice[i];
            answer += dice[i];
        }
        cout << answer-max << endl;
    }
    else
    {
        for (int i = 0; i < p2.size(); i++)
            c2.push_back(dice[p2[i][0]]+dice[p2[i][1]]);
        
        for (int i = 0; i < p3.size(); i++)
            c3.push_back(dice[p3[i][0]]+dice[p3[i][1]]+dice[p3[i][2]]);
        
        answer = *min_element(dice.begin(), dice.end()) * (((n-2) * (n-2) * 5) + ((n-2) * 4));
        answer += *min_element(c2.begin(), c2.end()) * ((n-1) * 8 - 4);
        answer += *min_element(c3.begin(), c3.end()) * 4;

        cout << answer << endl;
    }

    return 0;
}
