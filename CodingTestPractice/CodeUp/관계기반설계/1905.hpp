#include <iostream>

using namespace std;

int sum = 0;
void Sum(int n) {
	if (n <= 0)return;
	Sum(n - 1);
	sum += n;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	Sum(N);
	cout << sum;

	return 0;
}