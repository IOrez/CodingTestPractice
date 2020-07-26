#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 999999999
int N, M, Flag, P;
int set[40001];
int DP[40002];

void solution(vector<int>& v)
{
	DP[N] = 1;
	for (int i = N-1; i >=1; --i)
	{
		DP[i] = MAX;
		int Cnt = 0; ++Flag;
		for (int j = 0; j <= (N-i); ++j)
		{
			if (set[v[i+j]] != Flag)
			{
				set[v[i+j]] = Flag;
				Cnt++; P = pow(Cnt, 2);
				if (P >= (N - i + 1))break;
				if (Cnt == M && P < DP[i]) { DP[i] = P; break; }
			}
			if (P + DP[i + j + 1] < DP[i])DP[i] = P + DP[i + j + 1];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	vector<int> v(N+1);
	for (int i = 1; i <= N;++i)cin >> v[i];
	solution(v);
	cout << DP[1];
	return 0;
}