#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K,Max;

int solution(vector<long long>& table,long long left, long long right) {
	if (left > right) return right;
	long long mid = (left + right) / 2;
	if (mid == 0)return right;
	long long Sum = 0;
	for (auto& i : table)
		Sum += i / mid;

	if (K > Sum)
		return solution(table, left, mid - 1);
	else
		return solution(table, mid + 1, right);

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	vector<long long> table(N);
	for (auto& i : table)
		cin >> i;
	sort(table.begin(), table.end());
	cout << solution(table, 0, table[N - 1]);
	return 0;
}