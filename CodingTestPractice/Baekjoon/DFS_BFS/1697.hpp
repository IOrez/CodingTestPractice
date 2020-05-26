#include <iostream>
#include <functional>
#include <queue>

using namespace std;
int  me, bro;
bool check[100001];

function<int(int)> func[3]{ [&](int x) {return x - 1; },[&](int x) {return x + 1; },[&](int x) {return 2 * x; } };
void solution()
{
	queue<pair<int,int> > que;
	que.push({me,0});
	check[me] = true;
	while (!que.empty())
	{
		auto pos = que.front().first;
		auto cnt = que.front().second;
		que.pop();
		if (pos == bro)
		{
			cout << cnt; exit(0);
		}
		for (int i = 0; i < 3; ++i)
		{
			auto n_pos = func[i](pos);
			if (n_pos < 0 || n_pos>100000)continue;
			if (check[n_pos])continue;
			check[n_pos] = true;
			que.push({ n_pos,cnt + 1 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> me >> bro;
	solution();
	return 0;
}