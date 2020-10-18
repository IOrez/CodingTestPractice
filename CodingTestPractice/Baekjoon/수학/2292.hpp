#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, Cnt = 0;
	cin >> N;
	for (int i = 1, step = 1; N > 0; N -= step, Cnt++,step=6*i,i++) {}
	cout << Cnt;
	return 0;
}