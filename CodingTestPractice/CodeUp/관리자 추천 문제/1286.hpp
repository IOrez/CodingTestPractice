#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int number;
	int Min = std::numeric_limits<int>::max();
	int Max = std::numeric_limits<int>::min();
	for (int i = 0; i < 5; ++i)
	{
		cin >> number;
		Min = min(Min, number);
		Max = max(Max, number);
	}

	cout << Max << '\n' << Min << '\n';

	return 0;
}