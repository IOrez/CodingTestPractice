#include <iostream>
#include <string>
#pragma warning(disable:4996)


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	int x = 0;
	std::string s;
	scanf("%d", &n);
	while (n--)
	{
		std::cin >> s;
		if (s[0] == '+' || s[2] == '+')x += 1;
		else if (s[0] == '-' || s[2] == '-')x -= 1;
	}
	printf("%d", x);
	return 0;
}