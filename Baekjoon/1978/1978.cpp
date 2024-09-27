#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    for (int i=n/2; i>1; i--)
        if (n % i==0)
            return false;
    return true;
}

int main()
{
    int N, cnt=0;
    cin >> N;

    vector<int> v(N);
    for (int i=0; i<N; i++)
        cin >> v[i];
    
    for (int n: v)
    {
        if (n==1)
            continue;
        else if (isPrime(n))
            cnt += 1;
    }

    cout << cnt << endl;

    return 0;
}