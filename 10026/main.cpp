#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void BFS(vector<vector<char>>& map, vector<vector<bool>>& visited, int N, int x, int y, bool isWeak=false)
{
    vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    queue<pair<int, int>> queue;

    queue.push({x,y});

    while (queue.size()>0)
    {
        pair<int, int> current = queue.front();
        queue.pop();

        for (int i=0; i<dir.size(); i++)
        {
            int nx = current.first + dir[i].first;
            int ny = current.second + dir[i].second;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (!isWeak)
            {
                if (!visited[nx][ny] && map[nx][ny] == map[current.first][current.second])
                {
                    queue.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            else
            {
                if (!visited[nx][ny] && map[nx][ny] == map[current.first][current.second])
                {
                    queue.push({nx, ny});
                    visited[nx][ny] = true;
                }
                else if (!visited[nx][ny] && ((map[nx][ny] == 'R' && map[current.first][current.second] == 'G') || (map[nx][ny] == 'G' && map[current.first][current.second] == 'R')))
                {
                    queue.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main()
{
    pair<int, int> answer = {0, 0};
    int N;
    cin >> N;

    vector<vector<char>> map(N, vector<char>(N));
    vector<vector<bool>> visited_normal(N, vector<bool>(N));
    vector<vector<bool>> visited_weak(N, vector<bool>(N));

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (!visited_normal[i][j])
            {
                BFS(map, visited_normal, N, i, j);
                answer.first++;
            }
            if (!visited_weak[i][j])
            {
                BFS(map, visited_weak, N, i, j, true);
                answer.second++;
            }
        }
    }

    cout << answer.first << " " << answer.second << endl;

    return 0;
}