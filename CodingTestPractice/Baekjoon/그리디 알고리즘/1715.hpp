#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N;

int solution(vector<int>& v) {
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i)
		pq.push(-v[i]);
	
	int result = 0;
	while (pq.size() != 1) {
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		result += first + second;
		pq.push(first + second);
	}

	return -result;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)
		cin >> i;

	cout << solution(v);



	return 0;
}