#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    int c1, c2, c3, sum=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (i == j || j == k || i == k)
                    continue;
                if ((cards[i]+cards[j]+cards[k]) > sum && (cards[i]+cards[j]+cards[k])<=M)
                    sum = cards[i]+cards[j]+cards[k];
            }
        }
    }

    cout << sum << endl;

    return 0;
}