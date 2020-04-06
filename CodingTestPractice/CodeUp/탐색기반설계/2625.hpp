#include <iostream>
using namespace std;

int Case[101];

void init()
{
	for (int i = 1; i <= 33; ++i)
		for (int j = i; j < 101; ++j)
			for (int k = j; k < 101; ++k)
			{
				if (i + j + k > 100)break;
				if (i + j <= k)break;
				Case[i + j + k]++;
			}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	int n;
	cin >> n;
	cout << Case[n];
	return 0;
}