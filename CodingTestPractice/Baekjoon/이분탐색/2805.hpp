#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int table[1000001];
int solution(int s, int e)
{
	if (s > e)return e;
	int mid = (s + e) / 2;
	long long sum = 0;
	auto iter = lower_bound(table, table+N, mid);
	for (; iter != table+N; ++iter)
		sum += *iter - mid;
	
	if (sum < M)return solution(s, mid-1);
	else if (sum > M)return solution(mid+1, e);
	else return mid;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)cin >> table[i];
	sort(table+0, table+N);
	int result = solution(0, table[N-1]);
	cout << result << '\n';
	return 0;
}