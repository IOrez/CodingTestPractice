#include <iostream>

using namespace std;

char str[100001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	while (N--)
	{
		int resultStrSize;
		cin >> resultStrSize;
		string resultStr;
		cin >> str;
		resultStr = str;
		string s[2];
		bool isMeet1 = false;

		s[0].reserve(resultStrSize); s[1].reserve(resultStrSize);
		for (auto i = 0; i < resultStrSize; ++i)
		{
			char ch = resultStr[i];
			
			if (!isMeet1)
			{
				if (ch == '2')
				{
					s[0].push_back('1');
					s[1].push_back('1');
				}
				else if (ch == '1')
				{
					s[0].push_back('1');
					s[1].push_back('0');
					isMeet1 = true;
				}
				else
				{
					s[0].push_back('0');
					s[1].push_back('0');
				}
			}
			else
			{
				s[0].push_back('0');
				s[1].push_back(ch);
			}
		}
		cout << s[0].c_str() << endl;
		cout << s[1].c_str() << endl;
	}
	return 0;
}