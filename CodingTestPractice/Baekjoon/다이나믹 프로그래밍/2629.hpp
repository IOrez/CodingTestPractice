#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool DP[31][55001];
vector<int> vWeight;
vector<int> vTarget;
int N, M, W, T;

void Solution(int i, int w)
{
	if (N < i || DP[i][w] == true )
		return;

	DP[i][w] = true;

	Solution(i + 1, w);
	Solution(i + 1, w + vWeight[i]);
	Solution(i + 1, abs(w - vWeight[i]));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nSum = 0;
	cin >> N;
	vWeight.resize(N+1);
	for (int i = 0; i < N; i++)
	{
		cin >> W;
		vWeight[i] = W;
	}

	cin >> M;
	vTarget.resize(M+1);
	for (int i = 0; i < M; i++)
	{
		cin >> T;
		vTarget[i] = T;
	}

	Solution(0, 0);

	for (int i = 0; i < M; i++)
	{
		string ans = "N ";
		int t = vTarget[i];
		for (int j = 0 ; j <= N; j++)
		{
			if (DP[j][t] == true)
			{
				ans = "Y ";
				break;
			}
		}
		cout << ans;
	}

	return 0;
}