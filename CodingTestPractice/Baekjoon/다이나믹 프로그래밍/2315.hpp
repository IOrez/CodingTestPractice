#include <cstdio>
#include <cstring>
#include <cstdlib>

#pragma warning(disable:4996)

typedef unsigned long long ull;

void MakeTable(ull***& EE, ull***& PP, int n)
{
	EE = (ull***)calloc(n + 1, sizeof(ull**));
	for (int i = 1; i <= n; ++i)EE[i] = (ull**)calloc(n + 1, sizeof(ull*));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			EE[i][j] = (ull*)calloc(2, sizeof(ull));

	PP = (ull***)calloc(n + 1, sizeof(ull**));
	for (int i = 1; i <= n; ++i)PP[i] = (ull**)calloc(n + 1, sizeof(ull*));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			PP[i][j] = (ull*)calloc(2, sizeof(ull));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			EE[i][j][0] = EE[i][j][1] = 1000000000000;
}

void ReleaseTable(ull***& EE, ull***& PP, int n)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			free(EE[i][j]);

	for (int i = 1; i <= n; ++i)free(EE[i]);
	free(EE);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			free(PP[i][j]);

	for (int i = 1; i <= n; ++i)free(PP[i]);
	free(PP);
}

ull MinWaste(ull***& EE, ull***& PP, ull*& WS, ull*& D, int N, int m)
{
	EE[m][m][0] = EE[m][m][1] = 0;
	for (int L = m; L >= 1; --L)
	{
		for (int R = m; R <= N; ++R)
		{
			if (R - 1 >= m)
			{
				ull val1 = EE[L][R - 1][0] + (D[R] - D[L]) * (WS[N] - WS[R - 1] + WS[L - 1]);
				ull val2 = EE[L][R - 1][1] + (D[R] - D[R - 1]) * (WS[N] - WS[R - 1] + WS[L - 1]);

				if (val1 <= val2)
				{
					EE[L][R][1] = val1;
				}
				else
				{
					EE[L][R][1] = val2;
				}
			}

			if (L + 1 <= m)
			{
				ull val1 = EE[L + 1][R][0] + (D[L + 1] - D[L]) * (WS[N] - WS[R] + WS[L]);
				ull val2 = EE[L + 1][R][1] + (D[R] - D[L]) * (WS[N] - WS[R] + WS[L]);

				if (val1 <= val2)
				{
					EE[L][R][0] = val1;
				}
				else
				{
					EE[L][R][0] = val2;
				}
			}
		}
	}
	return EE[1][N][0] <= EE[1][N][1] ? EE[1][N][0] : EE[1][N][1];
}
int main()
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	ull* W = (ull*)calloc(n + 1, sizeof(ull));
	ull* D = (ull*)calloc(n + 1, sizeof(ull));
	ull* WS = (ull*)calloc(n + 1, sizeof(ull));
	ull*** EE = nullptr;
	ull*** PP = nullptr;

	MakeTable(EE, PP, n);
	EE[m][m][0] = EE[m][m][1] = 0;

	for (int i = 1; i <= n; ++i)
	{
		scanf("%llu %llu", &D[i], &W[i]);
		WS[i] = WS[i - 1] + W[i];
	}

	printf("%llu\n", MinWaste(EE, PP, WS, D, n, m));


	ReleaseTable(EE, PP, n);
	free(W);
	free(D);

	return 0;
}