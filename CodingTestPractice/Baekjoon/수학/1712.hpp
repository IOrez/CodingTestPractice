#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int A, B, C, Result = 1;
	cin >> A >> B >> C;
	if (B >= C)
		cout << -1;
	else
	{
		Result += A / (C - B);
		cout << Result;
	}

	return 0;
}