#include <iostream>
#include <vector>
#include <queue>


using namespace std;
queue<int> que;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K,Cnt;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		que.push(i);
	Cnt = K;
	while (!que.empty()) {
		int num = que.front();
		que.pop();
		if (--Cnt == 0) {
			v.push_back(num);
			Cnt = K;
		}
		else
			que.push(num);
	}
	cout << "<";
	for (auto i = 0; i < v.size() - 1; ++i)
		cout << v[i] << ", ";
	cout << v[v.size() - 1] << ">";
	return 0;
}