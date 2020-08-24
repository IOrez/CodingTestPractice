#include <iostream>
#include <vector>

using namespace std;
int N, M,Table[100],Max;
vector<int> v;

void solution(int idx) {
	if (v.size() == 3) {
		int Sum = 0;
		for (auto& i : v)
			Sum+=i;
		if (Max < Sum && M >= Sum)Max = Sum;
		return;
	}
	for (int i = idx; i < N; ++i) {
		v.push_back(Table[i]);
		solution(i + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> Table[i];
	solution(0);
	cout << Max;
	return 0;
}