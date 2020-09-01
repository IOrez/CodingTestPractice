#include <iostream>
using namespace std;
int N;

void solution() {
	int p[3] = { 1,0,0 };
	for (int i = 0; i < N; ++i){
		p[2] = p[0] + p[1];
		p[0] = p[1];
		p[1] = p[2];
	}
	cout << p[1];
}
int main() {
	cin >> N;
	solution();
	return 0;
}