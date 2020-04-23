#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	priority_queue<int> pq;
	priority_queue<int> nq;
	int result = 0;
	int val = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		if (val > 1)pq.push(val);
		else if (val < 1)nq.push(-val);
		else result += val;
	}
	
	while (!pq.empty())
	{
		val = pq.top(); pq.pop();
		if (pq.empty()) { result += val; break; }
		result += (val * pq.top());
		pq.pop();
	}

	while (!nq.empty())
	{
		val = -nq.top(); nq.pop();
		if (nq.empty()) { result += val; break; }
		result += (val * (-nq.top()));
		nq.pop();
	}

	cout << result;

	return 0;
}