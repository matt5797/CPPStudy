#include <vector>
#include <cmath>

using namespace std;

constexpr double BallDiameter = 2;

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    double magnitude = sqrt(hitVector[0] * hitVector[0] + hitVector[1] * hitVector[1]);  // 벡터 크기
    
    // 방향 벡터 정규화
    double vx = hitVector[0] / magnitude;
    double vy = hitVector[1] / magnitude;
    
    // 최대 x, y 좌표를 구해 임의의 당구대 범위 설정
    double max_x = 0, max_y = 0;
    for (auto& pos : objectBallPosList) {
        max_x = max(max_x, pos[0]);
        max_y = max(max_y, pos[1]);
    }

    double x = 0.0, y = 0.0;
    while(x<max_x && y<max_y)
    {
        // 큐 볼을 방향 벡터만큼 이동
        x += vx;
        y += vy;

        // 현재 위치에서 모든 오브젝트 볼과의 충돌 여부를 확인
        for (int i = 0; i < objectBallPosList.size(); i++) {
            double obj_x = objectBallPosList[i][0];
            double obj_y = objectBallPosList[i][1];

            // 현재 큐 볼과 오브젝트 볼 간의 거리 제곱 계산
            double dx = x - obj_x;
            double dy = y - obj_y;
            double distance = sqrt(dx * dx + dy * dy);

            // 거리가 충돌 거리 이내인 경우 충돌로 간주
            if (distance <= 2)
                return i;
        }
    }

    // 충돌이 없으면 -1 반환
    return -1;
}

// 틀린 버전