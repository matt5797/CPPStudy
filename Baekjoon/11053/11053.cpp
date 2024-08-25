#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    vector<int> dp(n, 1); // i까지의 원소를 사용했을 때 가장 긴 증가하는 부분 수열의 길이

    for (int i = 1; i < n; i++)
        for (int j = i; j >= 0; j--)
            if (A[j]<A[i])
                dp[i] = max(dp[i], dp[j]+1);
    
    int answer = 0;
    for (auto d: dp)
        answer = max(answer, d);
    cout << answer << endl;

    return 0;
}