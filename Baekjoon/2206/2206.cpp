#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> map;
    for (int i=0; i<N; i++)
    {
        vector<bool> row;
        string temp;
        cin >> temp;

        for (char c : temp)
            row.push_back((c=='1')?true:false);
        map.push_back(row);
    }

    int level = 0;
    vector<pair<int,int>> oper = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false))); // 0에는 벽 통과 이전, 1에는 벽 통과 이후
    queue<vector<int>> q; // [x, y, 벽통과여부, 단계]
    q.push({0,0,false,1});

    while(!q.empty())
    {
        vector<int> front = q.front();
        q.pop();

        if (front[0]>=N-1 && front[1]>=M-1)
        {
            level = front[3];
            break;
        }

        for (pair<int,int> next : oper)
        {
            int nx = front[0] + next.first;
            int ny = front[1] + next.second;

            // 한칸 이동
            if (nx>=0 && nx<N && ny>=0 && ny<M)
            {
                if (!map[nx][ny] && ((front[2]==0 && !visited[nx][ny][0]) || (front[2]==1 && !visited[nx][ny][0] && !visited[nx][ny][1])))
                {
                    visited[nx][ny][front[2]] = true;
                    q.push({nx, ny, front[2], front[3]+1});
                }
                // 벽을 부술 수 있으면
                if (!front[2] && map[nx][ny] && !visited[nx][ny][1])
                {
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, true, front[3]+1});
                }
            }
        }
    }

    if (level==0)
        level = -1;

    cout << level << endl;

    return 0;
}