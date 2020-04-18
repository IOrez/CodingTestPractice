#include <iostream>
#include <stack>

using namespace std;
stack<pair<int, int>> st;

int HI[80001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> HI[i];

	st.push({ HI[N],0 });
	long long int cnt = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		int top = st.top().first;
		if (HI[i] <= top)st.push({ HI[i],0});
		else
		{
			long long int pop_cnt = 0;
			while (!st.empty()&&(top = st.top().first) < HI[i])
			{
				cnt++;
				pop_cnt++;
				cnt+=st.top().second;
				pop_cnt += st.top().second;
				st.pop();
			}
			st.push({ HI[i],pop_cnt });
		}
	}
	cout << cnt;

	return 0;
}