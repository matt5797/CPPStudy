#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> sid = { 30,25,22,20,18,15,12,10 };
vector<int> sfirst = { 12,15,20 };

int main()
{
	int answer = 0;
	map<int, bool> smap;

	sort(sid.begin(), sid.end(), greater<int>());
	
	for (auto x : sid)
	{
		for (auto y : sfirst)
		{
			if (x == y)
				smap[x] = true;
		}
		if (!smap.count(x))
			smap[x] = false;
	}

	while (true)
	{
		auto it = sid.begin();

		int index1 = -1;
		int index2 = -1;

		for (int i = 0; i < sid.size(); i++)
		{
			if (i>1 && smap[sid[i]])
			{
				index1 = i;
				answer++;
				
				for (int j = i+1; j < sid.size(); j++)
				{
					if (smap[sid[j]])
					{
						index2 = j;
						answer++;
						break;
					}
				}

				if (index2 != -1)
					sid.erase(sid.begin() + index2);
				else if (index1 < sid.size())
					sid.erase(sid.begin() + index1 + 1);

				sid.erase(sid.begin() + index1);
				sid.erase(sid.begin(), sid.begin() + 2);
			}
		}

		if (sid.size() <= 4)
		{
			for (auto id : sid)
				if (smap[id])
					answer++;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}