#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
vector<vector<int>> answers;

void dfs(vector<int> seq, vector<bool> visited)
{
    if (seq.size() == m)
    {
        answers.push_back(seq);
        return;
    }

    for (int i=0; i<n; i++)
    {
        if (visited[i])
            continue;
        seq.push_back(v[i]);
        visited[i] = true;
        dfs(seq, visited);
        seq.pop_back();
        visited[i] = false;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i<n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<bool> visited(n, false);

    sort(v.begin(), v.end());

    dfs({}, visited);

    for (auto answer : answers)
    {
        for (int i = 0; i<m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
    }

    return 0;
}
