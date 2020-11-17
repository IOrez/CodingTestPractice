#include <iostream>
#include <string>
using namespace std;
string name[2] = { "SK","CY" };
int DP[1001];

void solution(int N) {
	DP[1] = 1;
	for (int i = 1; i+2 <= N; i+=2)
		DP[i + 2] = 1;
}
int main() {
	int N;
	cin >> N;
	solution(N);
	cout << name[DP[N]% 2];
	return 0;

}