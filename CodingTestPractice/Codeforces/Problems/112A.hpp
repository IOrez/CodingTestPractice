#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);

	int result = 0;
	for (auto i = 0; i < s1.size(); ++i)
	{
		if (s1[i] < s2[i]) { result = -1; break; }
		else if (s1[i] > s2[i]) { result = 1; break; }
	}
	printf("%d", result);
	return 0;
}