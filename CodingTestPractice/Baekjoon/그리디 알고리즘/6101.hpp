#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N, M, P;
vector<int> vp;
int check[40001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	vp.push_back(0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> P;
		if (vp.back() == P)continue;
		vp.push_back(P);
	}
	unsigned long long sum = 0;
	for (int i = 1; i < vp.size()-1;)
	{
		int j = i + 1;
		int Min = j - i;
		int MinIdx = j;
		check[i] = i;
		int s = 1;
		for (; j < vp.size();++j)
		{
			if (check[j]!=i) { check[j] = i; s++; }
			unsigned long long val = pow(s, 2);
			if (j - i + 1 > val)
			{
				Min = val;
				MinIdx = j;
			}
		}
		sum += Min;
		i = MinIdx;
	}
	cout << sum;
	return 0;
}