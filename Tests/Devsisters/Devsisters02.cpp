#include <vector>

using namespace std;

int solution(vector<vector<int>> field, int farmSize) {
    int answer = 101;
    int h = field.size();
    int w = field[0].size();

    // 좌상 기준 좌표를 전체 탐색
    for (int i = 0; i <= h - farmSize; i++) {
        for (int j = 0; j <= w - farmSize; j++) {
            bool hasPoison = false;
            int stones = 0;
            
            for (int x = i; x < i + farmSize; x++) {
                for (int y = j; y < j + farmSize; y++) {
                    if (field[x][y] == 2) { // 독버섯이 있다면 제외
                        hasPoison = true;
                        break;
                    } else if (field[x][y] == 1) {
                        stones++;
                    }
                }
                if (hasPoison)
                    break;
            }

            // 최소값 갱신
            if (!hasPoison)
                answer = min(answer, stones);
        }
    }

    return (answer == 101) ? -1 : answer;
}
