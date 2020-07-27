#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	vector<int> v;
	for (int i = 0; i < 7; ++i)
	{
		int num;
		cin >> num;
		if (num % 2 == 1)v.push_back(num);
	}

	int result = -1;
	if (!v.empty())
	{
		result = 0;
		for (auto& i : v)result += i;
	}
	cout << result;
	return 0;
}