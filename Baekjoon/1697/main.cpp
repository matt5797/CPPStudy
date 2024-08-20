#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    queue<pair<int, int>> queue;
    vector<bool> visited(100000, false);
    vector<pair<int, int>> nexts;
    pair<int, int> current;

    queue.push({n, 0});
    while (queue.size()>0) {
        current = queue.front();
        queue.pop();

        if (current.first==k)
            break;
        
        nexts = {{current.first-1,current.second+1}, {current.first+1,current.second+1}, {2*current.first,current.second+1}};

        for (int i=0; i<nexts.size(); i++) {
            if (nexts[i].first<0 || nexts[i].first>100000 || visited[nexts[i].first])
                continue;
            visited[nexts[i].first] = true;
            queue.push(nexts[i]);
        }
    }

    cout << current.second << endl;

    return 0;
}