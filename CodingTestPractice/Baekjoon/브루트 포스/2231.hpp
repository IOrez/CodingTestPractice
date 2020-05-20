#include <iostream>
#include <vector>
using namespace std;
int N;
unsigned int Min = -1;


void solution(const int n)
{
	int temp = n;
	unsigned int sum = n;
	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}
	if (sum == N && Min > n)Min = n;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		solution(i);
	if (Min == -1)Min = 0;
	cout << Min;
	return 0;
}