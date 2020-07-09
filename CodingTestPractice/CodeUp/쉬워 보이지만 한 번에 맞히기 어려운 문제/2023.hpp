#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	vector<char> cs;
	cin >> n;
	while (n != 0)
	{
		int m = n % 26;
		char ch = (char)(m + 'A' - 1);
		if (m == 0)
		{
			n -= 1;
			ch = 'Z';
		}
		n /= 26;
		cs.insert(cs.begin(), ch);
	}

	for (auto& c : cs)
		cout << c;
	return 0;
}