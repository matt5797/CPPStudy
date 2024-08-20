#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M, answer=0;

	cin >> N >> M;

	vector<int> A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	auto l = A.begin();
	auto r = A.begin();
	int acc = *l;

	while (l!=A.end())
	{
		if (acc == M)
			answer++;

		// r을 우측으로 이동
		if ((r+1)!=A.end() && abs(M - acc) > abs(M - (acc + *(r + 1))))
			acc += *(++r);
		// r을 좌측으로 이동
		else if (abs(M - acc) > abs(M - (acc - *r)))
			acc -= *(r--);
		// l을 우측으로 이동
		else
			acc -= *(l++);
	}

	cout << answer << endl;

	return 0;
}