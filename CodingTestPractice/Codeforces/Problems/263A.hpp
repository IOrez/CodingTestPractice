#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int posx, posy;
	for (int i =1; i <= 5; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			int val;
			cin >> val;
			if (val == 1)
			{
				posx = j;
				posy = i;
			}
		}
	}
	int moveX = 3 - posx;
	if (moveX < 0)moveX *= -1;

	int moveY = 3 - posy;
	if (moveY < 0)moveY *= -1;

	cout << moveX + moveY;
	return 0;
}