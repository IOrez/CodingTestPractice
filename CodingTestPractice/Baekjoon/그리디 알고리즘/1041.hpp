#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>
using namespace std;

int Min(initializer_list<long long> list)
{
	return *min_element(list.begin(), list.end());
}

void init(vector<long long>& v, vector<long long>& caseV)
{
	caseV[0] = 99999999999;
	caseV[1] = 99999999999;
	caseV[2] = 99999999999;
	caseV[3] = 99999999999;
	int sum = 0;
	for (auto& i : v)sum += i;
	for (int i = 0; i < v.size(); ++i)
	{
		caseV[0] = Min({ caseV[0],v[i] });
		caseV[3] = Min({ caseV[3],sum - v[5 - i] });
	}
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (i == j)continue;
			if (i + j == 5)continue;
			caseV[1] = Min({ caseV[1],v[i]+v[j] });

			for (int k = 0; k < v.size(); ++k)
			{
				if (i == k || j == k)continue;
				if (k == 5 - i|| k == 5 - j)continue;
				caseV[2] = Min({ caseV[2],v[i] + v[j] + v[k] });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n;
	vector<long long> v(6);
	vector<long long> caseV(4);
	cin >> n;
	for (auto& i : v)cin >> i;
	int min[4];
	init(v, caseV);

	min[0] = caseV[0];
	min[1] = caseV[1];
	min[2] = caseV[2];
	min[3] = caseV[3];

	long long result = 0;
	if (n == 1)result = min[3];
	else if (n == 2)
	{
		result += min[2] * 4;
		result += min[1] * 4;
	}
	else
	{
		result += min[2] * 4;
		result += min[1] * (n - 2) * 4;
		result += min[1] * (n - 1) * 4;
		result += min[0] * (n - 2) * (n - 2);
		result += min[0] * (n - 2) * (n - 1) * 4;
	}

	cout << result;
	return 0;
}