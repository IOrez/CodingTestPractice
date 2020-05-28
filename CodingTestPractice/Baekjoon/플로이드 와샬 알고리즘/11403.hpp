#include <iostream>

using namespace std;

bool check[100][100];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> check[i][j];

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
			{
				if (check[i][j])continue;
				if(check[i][k]&&check[k][j])
					check[i][j] = true;
			}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << check[i][j] << " ";
		cout << endl;
	}
		
	return 0;
}