#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[2] < b[2])
        return true;
    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;
    for (int i=0; i<E; i++)
    {
        vector<int> edge(3);
        cin >> edge[0] >> edge[1] >> edge[2];
        edges.push_back(edge);
    }

    sort(edges.begin(), edges.end(), comp);

    int result = 0;
    vector<set<int>> trees;
    for (vector<int>& edge: edges)
    {
        int a = edge[0], b = edge[1], c = edge[2]; // 정점1, 정점2, 간선
        int index1 = -1, index2 = -1;

        for (int i=0; i<trees.size(); i++)
        {
            if (trees[i].count(a))
                index1 = i;
            if (trees[i].count(b))
                index2 = i;
        }

        // 만약 모든 트리에 속해있지 않다면 새롭게 트리를 생성
        if (index1 == -1 && index2 == -1)
        {
            trees.push_back(set<int> {a, b});
        }
        // 만약 양쪽이 트리에 속하면 같은 트리에 속한다면 제외
        else if (index1 == index2)
            continue;
        // 만약 양쪽이 서로 다른 트리에 속하면 두 트리를 결합
        else if (index1 >= 0 && index2 >= 0)
        {
            for (int element: trees[index2])
                trees[index1].insert(element);
            trees.erase(trees.begin() + index2);
        }
        // 만약 한쪽만 트리에 속해있다면 트리에 추가
        else if (index1 >= 0 || index2 >= 0)
        {
            int index = (index1>=0)? index1: index2;
            trees[index].insert(a);
            trees[index].insert(b);
        }
        result += c;
    }

    cout << result << endl;

    return 0;
}