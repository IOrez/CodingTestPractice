#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& obj1,const pair<int, int>& obj2)
{
	if (obj1.second != obj2.second)return obj1.second < obj2.second;
	return obj1.first < obj2.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testCase = 0;
	cin >> testCase;
	while (testCase--)
	{
		int N, M;
		cin >> N >> M;
		vector<bool> books(N+1);
		vector<pair<int, int>> student(M);
		for (int i = 0; i < M; ++i)
			cin >> student[i].first >> student[i].second;

		sort(student.begin(), student.end(), cmp);

		int cnt = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = student[i].first; j <= student[i].second; ++j)
			{
				if (books[j])continue;
				books[j] = true;
				cnt++;
				break;
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}