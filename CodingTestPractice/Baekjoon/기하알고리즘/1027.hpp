#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int cnt[50];
pair<int, int> vDif;

int Solution(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		vDif = make_pair(0, 0);
		double mMax,t;
		for (int j = i+1; j < v.size(); j++)
		{
			int xdif = j - i;
			int ydif = v[j] - v[i];
			double m = (double)ydif / xdif;
			if (j == i + 1)
			{
				mMax = m;
				t = j;
				cnt[i]++;
				continue;
			}

			if (mMax < m)
			{
				mMax = m;
				t = j;
				cnt[i]++;
				continue;
			}

			double k = v[t] - mMax * t;

			if (v[j] > mMax * j + k)
				cnt[i]++;
		}

		double mMin;
		for (int j = i - 1; j >= 0; j--)
		{
			int xdif = j - i;
			int ydif = v[j] - v[i];

			double m = (double)ydif / xdif;

			if (j == i - 1)
			{
				mMin = m;
				t = j;
				cnt[i]++;
				continue;
			}

			if (mMin > m)
			{
				mMin = m;
				t = j;
				cnt[i]++;
				continue;
			}

			double k = v[t] - mMin * t;

			if (v[j] > mMin * j + k)
				cnt[i]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		ans = max(ans, cnt[i]);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n,t;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}

	cout << Solution(v);
	return 0;
}