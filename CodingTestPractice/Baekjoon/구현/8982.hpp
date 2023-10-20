#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, K;
vector<int> vholl;
int depth[40001];
int f[40001];
int width;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a,b,c,d;
	cin >> N;
	cin >> a >> b;
	for (int i = 0; i < (N-2)/2; i++)
	{
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++)
			depth[j] = b;
	}
	cin >> a >> b;
	width = a;

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c >> d;
		vholl.push_back(a);
	}

	for (int i = 0; i < vholl.size(); i++)
	{
		int s = vholl[i];
		int h = depth[s];
		f[s] = h;
		for (int j = s - 1; j >= 0; j--)
		{
			if (h > depth[j])
				h = depth[j];

			if (f[j] < h)
				f[j] = h;
		}

		h = depth[s];

		for (int j = s + 1; j < width; j++)
		{
			if (h > depth[j])
				h = depth[j];

			if (f[j] < h)
				f[j] = h;
		}
	}

	int ans = 0;
	for (int i = 0; i < width; i++)
		ans += (depth[i] - f[i]);

	cout << ans;

	return 0;
}