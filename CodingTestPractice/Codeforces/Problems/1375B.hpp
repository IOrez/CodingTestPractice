#include <iostream>
using namespace std;

int table[300][300];
int N, M;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		bool check = true;
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				cin >> table[i][j];
				if ((i == 0 && j == 0) || (i == 0 && j == M - 1) || (i == N - 1 && j == 0) || (i == N - 1 && j == M - 1))
				{
					if (table[i][j] > 2)check = false;
					else table[i][j] = 2;
				}
				else if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
				{
					if (table[i][j] > 3)check = false;
					else table[i][j] = 3;
				}
				else
				{
					if (table[i][j] > 4)check = false;
					else table[i][j] = 4;
				}
			}

		if (check)
		{
			cout << "YES" << '\n';
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < M; ++j)
					cout << table[i][j] << " ";
				cout << '\n';
			}
		}
		else
			cout << "NO" << '\n';
	}

	return 0;
}