#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N, M, card;
    unordered_map<int, int> m;

    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    cin >> M;
    vector<int> finds(M);
    for (int i = 0; i < M; i++)
        cin >> finds[i];

    for (auto card : cards) {
        if (m.find(card) == m.end())
            m[card] = 1;
        else
            m[card]++;
    }

    for (auto card : finds)
        cout << m[card] << " ";
    cout << endl;

    return 0;
}