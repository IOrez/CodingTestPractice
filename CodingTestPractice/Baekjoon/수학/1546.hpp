#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	vector<double> score(N);
	for (auto& i : score)cin >> i;
	int MaxVal = *max_element(score.begin(), score.end());
	for (auto& i : score)
		i = i / MaxVal * 100;
	double Sum = 0;
	for (auto& i : score)
		Sum += i;
	cout << (double)Sum / N;

	return 0;
}