#include <iostream>
#include <string>
#pragma warning(disable:4996)

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string s;
	std::cin >> s;
	for (auto i = s.begin(); i != s.end(); ++i)
	{
		char ch = tolower(*i);
		if (ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' || ch == 'i')continue;
		else std::cout << "." << ch;
	}

	return 0;
}