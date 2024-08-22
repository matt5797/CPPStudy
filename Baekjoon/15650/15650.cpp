#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> answers;

void dfs(vector<int> seq, int num)
{
    // m이거나 n개에 도달하면 저장
    if (seq.size()>=m)
    {
        answers.push_back(seq);
        return;
    }
    if (num>n)
        return;
    // 이번 원소를 편입하거나 안하거나 분기
    dfs(seq, num+1);
    seq.push_back(num);
    dfs(seq, num+1);
}

int main()
{
    cin >> n >> m;

    dfs({}, 1);

    sort(answers.begin(), answers.end());

    for (auto answer : answers)
    {
        for (auto a : answer)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}