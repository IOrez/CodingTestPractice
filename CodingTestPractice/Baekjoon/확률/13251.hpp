#include <iostream>
#include <iomanip>
using namespace std;

int Color[51];
int M, K, Sum;
double P[51];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> Color[i];
		Sum += Color[i];
		P[i] = 1;
	}
	cin >> K;
	for (int c = 1; c <= M; ++c)
	{
		if (Color[c] < K) { P[c] = 0; continue; };
		for (int i = 0; i < K; ++i)
			P[c] *= ((double)(Color[c] - i))/(Sum - i);
	}

	double result = 0;
	for (int i = 1; i <= M; ++i)
		result += P[i];

	cout << fixed<< setprecision(18)<<result;
	return 0;
}