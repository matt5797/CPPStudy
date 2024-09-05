#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> costs(N, vector<int>(3));

    for (int i = 0; i<N; i++)
        for (int j=0; j<3; j++)
            cin >> costs[i][j];
    
    vector<vector<int>> results = costs;
    
    for (int i = 1; i<N; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (j==0)
                results[i][j] += min(results[i-1][1], results[i-1][2]);
            else if (j==1)
                results[i][j] += min(results[i-1][0], results[i-1][2]);
            else if (j==2)
                results[i][j] += min(results[i-1][0], results[i-1][1]);
        }
    }

    cout << *min_element(results.back().begin(), results.back().end()) << endl;

    return 0;
}