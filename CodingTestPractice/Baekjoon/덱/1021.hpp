#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int Size, N;
	cin >> Size >> N;
	deque<int> deq;
	vector<int> vec(N);
	for (int i = 1; i <= Size; ++i)
		deq.push_back(i);
	for (auto& i : vec)
		cin >> i;
	int cnt = 0;
	for (auto& i : vec) {
		auto iter = find(deq.begin(), deq.end(), i);
		int idx = iter - deq.begin();
		if (idx <= deq.size() / 2) {
			while (true) {
				if (deq.front() == i) { deq.pop_front(); break; }
				deq.push_back(deq.front());
				deq.pop_front();
				cnt++;
			}
		}
		else {
			while (true) {
				if (deq.front() == i) { deq.pop_front(); break; }
				deq.push_front(deq.back());
				deq.pop_back();
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}