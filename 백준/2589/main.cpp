#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    vector<vector<char>> map, map_origin;
    int max_line = 0;

    // map 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            row.push_back(input);
        }
        map.push_back(row);
    }
    map_origin = map;

    queue<vector<int>> queue;
    vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int nx, ny;

    // 각 육지 그룹들을 순회한다.
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            // 새로운 그룹을 찾는다.
            if (map[i][j] == 'L') {
                queue.push({i, j, 0});
                map[i][j] = 'R';

                vector<int> current;
                
                // 가장 깊은 지점을 찾는다.
                while (queue.size() > 0) {
                    current = queue.front();
                    queue.pop();

                    for (int i=0; i<dir.size(); i++) {
                        nx = current[0] + dir[i].first;
                        ny = current[1] + dir[i].second;

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        
                        if (map[nx][ny] == 'L') {
                            queue.push({nx, ny, current[2]+1});
                            map[nx][ny] = 'R';
                        }
                    }
                }
                map = map_origin;

                if (current[2]>max_line)
                    max_line = current[2];
            }
        }
    }

    cout << max_line << endl;

    return 0;
}