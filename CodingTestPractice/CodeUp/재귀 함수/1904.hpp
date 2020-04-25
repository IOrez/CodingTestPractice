#include <iostream>

using namespace std;

void solution(int a, int b)
{
	if (a > b)return;
	cout << a << " ";
	solution(a + 2, b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	if (a % 2 == 0)a += 1;
	solution(a, b);

	return 0;
}