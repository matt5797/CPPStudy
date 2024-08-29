#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
set<vector<int>> seqs;

void dfs(vector<int> seq, vector<int> visited)
{
    if (seq.size() == m)
    {
        seqs.insert(seq);
        return;
    }
    
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            seq.push_back(v[i]);
            visited[i] = true;
            dfs(seq, visited);
            seq.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> visited(n, false);

    sort(v.begin(), v.end());

    dfs({}, visited);

    for (auto seq: seqs)
    {
        for (auto s: seq)
        {
            cout << s << ' ';
        }
        cout << endl;
    }

    return 0;
}