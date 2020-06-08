#include <iostream>

using namespace std;

using ull = unsigned long long;

ull table[301][301];

ull solution(int N, int M)
{
	if (table[N][M] != 0)return table[N][M];
	else if (N == 1) { return M - 1; }
	else if (M == 1) { return N - 1; }

	ull val1, val2;
	if (N % 2 == 0)
		val1 = solution(N / 2, M) * 2;
	else
		val1 = solution(N / 2, M) + solution(N / 2 + 1, M);

	if (M % 2 == 0)
		val2 = solution(N, M / 2) * 2;
	else
		val2 = solution(N, M / 2) + solution(N, M / 2 + 1);

	table[N][M] = val1 < val2 ? val1 : val2;
	return ++table[N][M];
}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	cout << solution(N, M);
	return 0;
}