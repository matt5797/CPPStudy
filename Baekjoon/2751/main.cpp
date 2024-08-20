#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N;
    
    vector<int> numbers(N);

    for (int i=0; i<N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i=0; i<N; i++) {
        cout << numbers[i] << '\n';
    }

    return 0;
}