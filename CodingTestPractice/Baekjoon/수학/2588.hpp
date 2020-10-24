#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int A, B;
	cin >> A >> B;
	vector<int> v;
	while (B) {
		int i = B % 10;;
		v.push_back(A * i);
		B /= 10;
	}
	for (auto& i : v)
		cout << i << '\n';
	int Sum = 0;
	for (size_t i = 0; i < v.size(); ++i)
		Sum += v[i]*pow(10, i);
	cout << Sum;
	return 0;
}