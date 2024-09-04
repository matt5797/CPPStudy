#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> seqs;

void dfs(vector<int> seq, int idx)
{
    if (seq.size()>=m)
    {
        seqs.push_back(seq);
        return;
    }
    // 이번 숫자를 넣고 진행
    seq.push_back(idx);
    dfs(seq, idx);
    seq.pop_back();
    // 이번 숫자는 안넣고 넘기기
    if (idx<n)
        dfs(seq, idx+1);
}

int main()
{
    cin >> n >> m;

    dfs({}, 1);

    for (auto seq: seqs)
    {
        for (auto num: seq)
        {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}