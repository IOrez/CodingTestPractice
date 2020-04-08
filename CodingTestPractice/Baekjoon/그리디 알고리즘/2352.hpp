#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Arr[40001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Arr[i];

	vector<int> con;
	con.push_back(Arr[1]);
	for (int i = 2; i <= N; ++i)
	{
		if (con.back() < Arr[i])con.push_back(Arr[i]);
		else
		{
			auto iter = lower_bound(con.begin(), con.end(), Arr[i]);
			*iter = Arr[i];
		}
	}
	cout << con.size();
	return 0;
}
