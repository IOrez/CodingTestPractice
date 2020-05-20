#include <iostream>
using namespace std;

int N;
int Max;


void solution(int n)
{
	if (n > N)return;
	if (Max < n)Max = n;
	n *= 10;
	n += 7;
	solution(n);
	n -= 7;
	n += 4;
	solution(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	solution(0);
	cout << Max;
	return 0;
}