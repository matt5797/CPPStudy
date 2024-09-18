#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K, index=0;

    cin >> N >> K;
    
    vector<int> vec;
    vector<int> result;

    for (int i=0; i<N; i++)
        vec.push_back(i+1);

    cout << "<";
    while (vec.size() > 0)
    {
        int target = ((index+K-1) % vec.size());
        if (vec.size()<N)
            cout << ", ";
        cout << vec[target];
        vec.erase(vec.begin()+target);
        index = target;
    }
    cout << ">";

    return 0;
}