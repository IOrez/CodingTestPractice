#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	unsigned long long int sum_weight = 0;
	int weight = 0;
	int idx = -1;
	while (true)
	{
		weight++;
		if (sum_weight < weight)
		{
			idx++;
			if (idx == N) { idx = N - 1; }
			else
				sum_weight += v[idx];
		}

		if (weight-v[idx]<0||sum_weight<weight) { cout << weight; break; }
	}

	return 0;
}