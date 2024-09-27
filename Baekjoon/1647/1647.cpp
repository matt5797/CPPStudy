#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[2] < b[2])
        return true;
    return false;
}

// 루트 노드를 찾아서 반환
int find(int a)
{
    if (parent[a]==a)
        return a;
    return find(parent[a]);
}

// 두 유니온 트리를 병합
void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a==b) return;

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 두 노드가 연결되었는지 여부
bool isUnion(int a, int b)
{
    return find(a)==find(b);
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        parent.push_back(i);

    vector<vector<int>> edges;
    for (int i = 0; i < M; i++)
    {
        vector<int> edge(3);
        cin >> edge[0] >> edge[1] >> edge[2];
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), comp);

    int result = 0, max_cost = 0;
    for (vector<int>& edge: edges)
    {
        int a = edge[0]-1, b = edge[1]-1, c = edge[2];

        if (!isUnion(a, b)) // 연결 되지 않았을 경우
        {
            merge(a, b);
            result += c;
            max_cost = max(max_cost, c);
            N--;
        }
        if (N==1)
            break;
    }

    cout << result - max_cost << endl;

    return 0;
}