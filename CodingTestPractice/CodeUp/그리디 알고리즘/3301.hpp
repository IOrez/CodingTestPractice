#include <cstdio>
#include <limits>

#pragma warning(disable: 4996)

int greedy(int money)
{
	int sum = 0;
	sum += (money / 50000); money %= 50000;
	sum += (money / 10000); money %= 10000;
	sum += (money / 5000);	money %= 5000;
	sum += (money / 1000);	money %= 1000;
	sum += (money / 500);	money %= 500;
	sum += (money / 100);	money %= 100;
	sum += (money / 50);	money %= 50;
	sum += (money / 10);
	return sum;
}

int main()
{
	unsigned int money;
	scanf("%u", &money);
	int rest = greedy(money);
	printf("%d", rest);
	return 0;
}