#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool check[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int S, E, N, M;
	cin >> N;
	vector<int> table(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		cin >> table[i];
		check[i][i] = true;
	}
	for (int dia = 1; dia <= N - 1; ++dia)
		for (int i = 1; i + dia <= N; ++i)
		{
			bool c = check[i+1][i+dia-1];
			bool t = table[i] == table[i + dia];
			if (i + 1 > i + dia - 1)c = true;
			check[i][i + dia] = t * c;
		}
	cin >> M;
	while (M--)
	{
		cin >> S >> E;
		cout << check[S][E] << '\n';
	}
	return 0;
}