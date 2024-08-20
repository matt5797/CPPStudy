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

		// r�� �������� �̵�
		if ((r+1)!=A.end() && abs(M - acc) > abs(M - (acc + *(r + 1))))
			acc += *(++r);
		// r�� �������� �̵�
		else if (abs(M - acc) > abs(M - (acc - *r)))
			acc -= *(r--);
		// l�� �������� �̵�
		else
			acc -= *(l++);
	}

	cout << answer << endl;

	return 0;
}