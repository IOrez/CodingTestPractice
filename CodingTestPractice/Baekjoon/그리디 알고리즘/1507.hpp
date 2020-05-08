#include <iostream>

using namespace std;

int Table[20][20];
int RawTable[20][20];

#define INF	99999999

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> RawTable[i][j];
			Table[i][j] = RawTable[i][j];
		}


	
	for(int k = 0;k<N;++k)
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == j||i==k||k==j)continue;
				if (RawTable[i][j] == RawTable[i][k] + RawTable[k][j])
				{
					Table[i][j] = INF;
				}

			}
		}


	int result = 0;
	for(int i = 0;i<N;++i)
		for (int j = i; j < N; ++j)
			if (Table[i][j] != INF)result += Table[i][j];

	bool check = false;
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (Table[i][j] > Table[i][k] + Table[k][j])
					Table[i][j] = Table[i][k] + Table[k][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (RawTable[i][j] != Table[i][j])
				result = -1;

	cout << result;


	return 0;
}