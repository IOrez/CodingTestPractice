#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		que.push(i);

	while (que.size() != 1) {
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.front();
	return 0;
}