#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, L;
	cin >> N >> L;
	vector<int> v(N);
	float tapeEndPoint=0;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i) 
	{
		if (tapeEndPoint + 0.5 > v[i])continue;
		tapeEndPoint = v[i] - 0.5f + L;
		cnt++;
	}
	cout << cnt;
	return 0;
}