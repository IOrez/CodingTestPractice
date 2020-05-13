#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define SIZE 1001

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,a;
	cin >> N;
	vector<pair<int,int> > v(SIZE);
	for (int i = 1; i < SIZE; ++i)
		v[i].second = i;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		v[a].first++;
	}

	sort(v.begin(), v.end(), greater<pair<int, int>>());
	int sol1_s = v[0].second;
	int sol1_e = -1;
	int result = 0;
	bool flag = false;

	
	for(int i =1;i<v.size()-1;++i)
		if (v[i].first != v[i + 1].first)
		{
			sol1_e = v[i].second;
			break;
		}

	if (sol1_e != -1)
	{
		if (abs(sol1_s - sol1_e) < abs(sol1_s - v[1].second))
			sol1_e = v[1].second;
		result = abs(sol1_s - sol1_e);
	}

	cout << result;
	
	

	return 0;
}