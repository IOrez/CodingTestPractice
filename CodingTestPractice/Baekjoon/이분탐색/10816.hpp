#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> cards;

int solution(int number) {
	int result = 0;
	auto liter = lower_bound(cards.begin(), cards.end(), number);
	auto uiter = upper_bound(cards.begin(), cards.end(), number);
	if (liter != cards.end())
		result = uiter - liter;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int number;
		cin >> number;
		cards.push_back(number);
	}
	sort(cards.begin(), cards.end());
	
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int number;
		cin >> number;
		cout << solution(number) << ' ';
	}
	return 0;
}