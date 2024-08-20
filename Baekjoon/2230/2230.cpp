#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    pair<int, int> answer = {*(A.begin()), *(A.end()-1)};

    int l = 0, r = 0;

    while (l < N)
    {
        while (((r + 1) < N) && ((A[r] - A[l]) < M))
        {
            r++;
        }
        if ((A[r]-A[l]) >= M && (answer.second-answer.first) > (A[r]-A[l]))
        {
            answer = {A[l], A[r]};
        }
        if (A[l]-A[r]==M)
            break;
        l++;
    }

    cout << answer.second - answer.first << endl;

    return 0;
}