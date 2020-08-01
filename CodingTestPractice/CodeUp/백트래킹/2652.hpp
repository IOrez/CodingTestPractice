#include <iostream>
#include <vector>
using namespace std;
int N, K,Cnt;
vector<int> v;
void solution(int s)
{
	if (v.size() == K)
	{
		Cnt++;
		return;
	}
	else
		for (int i = s; i < N; i ++)
		{
			v.push_back(i);
			solution(i + 2);
			v.pop_back();
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	solution(0);
	cout << Cnt;
	return 0;
}