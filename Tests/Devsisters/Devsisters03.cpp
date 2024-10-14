#include <vector>
#include <cmath>

using namespace std;

constexpr double BallDiameter = 2;

int solution(vector<vector<double>> objectBallPosList, vector<double> hitVector) {
    int answer = -1;
    double minTime = -1;

    double dx = hitVector[0], dy = hitVector[1];

    for (int i = 0; i < objectBallPosList.size(); ++i) {
        double x0 = objectBallPosList[i][0];
        double y0 = objectBallPosList[i][1];

        // 이차방정식의 계수 a, b, c를 계산
        double a = dx * dx + dy * dy; // a = dx^2 + dy^2
        double b = -2 * (dx * x0 + dy * y0);  // b = -2*(dx*x0 + dy*y0)
        double c = x0 * x0 + y0 * y0 - BallDiameter * BallDiameter; // c = x0^2 + y0^2 - 4

        double D = b * b - 4 * a * c; // 판별식 D = b^2 - 4ac

        if (D > 0) { // 스치는 것도 제외
            double sqrtD = sqrt(D);
            double t1 = (-b - sqrtD) / (2 * a);
            double t2 = (-b + sqrtD) / (2 * a);

            // 양수인 t 중에서 가장 작은 값을 선택
            double t = -1;
            if (t1 > 0 && t2 > 0)
                t = min(t1, t2);
            else if (t1 > 0)
                t = t1;
            else if (t2 > 0)
                t = t2;

            if (t > 0) {
                if (minTime < 0 || t < minTime) {
                    minTime = t;
                    answer = i; // 현재 공의 인덱스로 갱신
                }
            }
        }
    }

    return answer;
}
