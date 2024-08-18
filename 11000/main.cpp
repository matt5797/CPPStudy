#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<pair<int, int>> courses(N);

    for (int i=0; i<N; i++)
    {
        cin >> courses[i].first >> courses[i].second;
    }

    // 시작 시간 기준으로 오름차순 정렬
    sort(courses.begin(), courses.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& course : courses)
    {
        // 만약 강의가 종료시간보다 늦게 시작하면
        if (!pq.empty() && course.first >= pq.top()) {
            // 강의 수행
            pq.pop();
            pq.push(course.second);
        }
        else {
            // 새로운 강의 추가
            pq.push(course.second);
        }
    }

    cout << pq.size() << endl;

    return 0;
}