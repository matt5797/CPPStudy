#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    queue<int> q;
    set<int> people;
    vector<set<int>> party_list;

    int num, temp;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        people.insert(temp);
        q.push(temp);
    }

    for (int i=0; i<M; i++)
    {
        cin >> num;
        set<int> party;
        for (int j = 0; j < num; j++)
        {
            cin >> temp;
            party.insert(temp);
        }
        party_list.push_back(party);
    }

    while(!q.empty())
    {
        int target = q.front();
        q.pop();
        
        for (int i=party_list.size()-1; i>=0; i--)
        {
            if (party_list[i].find(target) != party_list[i].end())
            {
                for (int person : party_list[i])
                {
                    if (people.find(person) == people.end())
                    {
                        people.insert(person);
                        q.push(person);
                    }
                }
                party_list.erase(party_list.begin()+i);
            }
        }
    }

    cout << party_list.size() << endl;

    return 0;
}
