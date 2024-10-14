#include <vector>

using namespace std;

// 현재 경험치와 완료한 퀘스트 상태에서 최대 완료 가능한 퀘스트 수를 반환
int dfs(vector<vector<int>>& quest, int exp, vector<bool>& visited)
{
    int max_count = 0;
    
    for (int i = 0; i < quest.size(); ++i)
    {
        // 현재 경험치로 퀘스트를 수행할 수 있는 경우
        if (!visited[i] && quest[i][0] <= exp)
        {
            visited[i] = true;
            max_count = max(max_count, 1 + dfs(quest, exp + quest[i][1], visited));
            visited[i] = false;
        }
    }

    return max_count;
}

int solution(vector<vector<int>> quest) {
    vector<bool> visited(quest.size(), false);

    return dfs(quest, 0, visited);
}