#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n, 0));
    for (int i=0; i<n; i++)
        for (int j=0; j<=i; j++)
            cin >> triangle[i][j];

    for (int i=n-2; i>=0; i--)
        for (int j=0; j<=i; j++)
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);

    cout << triangle[0][0];

    return 0;
}