#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, H,Sum = 0;
	cin >> N >> H;
	for (int i = 0; i < N; ++i)
	{
		int height; cin >> height;
		if (height > H)Sum += 2;
		else Sum += 1;
	}
	cout << Sum;
	return 0;
}