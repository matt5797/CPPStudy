#include <iostream>
#include <vector>

using namespace std;

int N;
int count = 0;

void dfs(vector<int> visited, int level)
{
    if (level>=N)
    {
        count++;
        return;
    }

    // 가능한 열 탐색
    for (int i = 0; i < N; i++)
    {
        bool found = false;

        // 같은 열이 있으면 안됨
        for (int j = 0; j < visited.size(); j++)
            if (visited[j] == i)
                found = true;
        
        // 대각선에도 있으면 안됨
        for (int j = 0; j < visited.size(); j++)
            if ((level-j) == abs(visited[j]-i))
                found = true;
        
        if (!found)
        {
            visited.push_back(i);
            dfs(visited, level+1);
            visited.pop_back();
        }
    }
}

int main()
{
    cin >> N;

    dfs({}, 0);

    cout << count << endl;

    return 0;
}