#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int number;
    vector<string> numbers;

    while (true)
    {
        cin >> number;
        if (number==0) break;
        numbers.push_back(to_string(number));
    }
    
    for (auto& number : numbers)
    {
        bool flag = false;
        for (int i=0; i<number.size()/2; i++)
        {
            if (number[i]!=number[number.size()-i-1])
            {
                flag = true;
                break;
            }
        }
        cout << (flag ? "no" : "yes") << endl;
    }

    return 0;
}