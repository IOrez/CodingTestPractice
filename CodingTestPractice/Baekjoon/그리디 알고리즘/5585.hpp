#include <cstdio>
#pragma warning(disable:4996)

int greed(int& money)
{
	int sum = 0;
	sum += (money / 500); money %= 500;
	sum += (money / 100); money %= 100;
	sum += (money / 50); money %= 50;
	sum += (money / 10); money %= 10;
	sum += (money / 5); money %= 5;
	sum += money;

	return sum;
}

int main()
{
	int money;
	scanf("%d", &money);
	money = 1000 - money;
	printf("%d",greed(money));
	return 0;
}