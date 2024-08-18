#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int N, M, max=0;

    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<pair<int,int>> zeros, virus;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0)
                zeros.push_back({i,j});
            else if (map[i][j] == 2)
                virus.push_back({i,j});
        }
    }

    for (int i=0; i<zeros.size(); i++) {
        for (int j=0; j<zeros.size(); j++) {
            if (i==j) continue;
            for (int k=0; k<zeros.size(); k++) {
                if (j==k || i==k) continue;

                visited = vector<vector<bool>>(N, vector<bool>(M, false));

                visited[zeros[i].first][zeros[i].second] = true;
                visited[zeros[j].first][zeros[j].second] = true;
                visited[zeros[k].first][zeros[k].second] = true;

                queue<pair<int, int>> queue;
                for (int i=0; i<virus.size(); i++) {
                    queue.push(virus[i]);
                    visited[virus[i].first][virus[i].second] = true;
                }

                vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
                while (!queue.empty()) {
                    auto current = queue.front();
                    queue.pop();

                    for (int i=0; i<dir.size(); i++) {
                        int nx = current.first + dir[i].first;
                        int ny = current.second + dir[i].second;

                        if (nx<0 || ny<0 || nx>=N || ny>=M) continue;

                        if (map[nx][ny]==0 && !visited[nx][ny]) {
                            queue.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }

                int safe = 0;
                for (int i=0; i<zeros.size(); i++) {
                    if (map[zeros[i].first][zeros[i].second]==0 && !visited[zeros[i].first][zeros[i].second]) {
                        safe++;
                    }
                }
                
                if (safe>max) {
                    max = safe;
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}
