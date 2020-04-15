#include <iostream>

using namespace std;
char str[8];

void backTracking(const int n, int i)
{
	if (i == n) {
		str[i] = '\0';
		cout << str<<"\n";
	}
	else
	{
		str[i] = 'O';
		backTracking(n, i + 1);
		str[i] = 'X';
		backTracking(n, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	backTracking(n, 0);

	return 0;
}