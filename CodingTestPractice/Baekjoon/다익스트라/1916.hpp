#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int dis[1001];
bool check[1001];
int N, M, S, E, Weight;

template <typename T>
T Max =  numeric_limits<T>::max();

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	vector<vector<pair<int, int>>> table(N + 1);
	for (int i = 0; i < M; ++i) {
		cin >> S >> E >> Weight;
		table[S].push_back({ E,Weight });
	}
	cin >> S >> E;
	for (int i = 1; i <= N; ++i)
		dis[i] = Max<int>;

	for (auto& o : table[S])
		dis[o.first] = min(dis[o.first],o.second);
	check[S] = true;
	while (true) {
		int Min = Max<int>;
		int  idx = -1;
		for (int i = 1; i <= N; ++i) {
			if (!check[i] && Min > dis[i]) {
				Min = dis[i];
				idx = i;
			}
		}
		if (idx == E) {
			cout << Min;
			break;
		}
		check[idx] = true;
		for (auto& o : table[idx])
			if (dis[o.first] > dis[idx] + o.second)dis[o.first] = dis[idx] + o.second;
	}
	return 0;
}