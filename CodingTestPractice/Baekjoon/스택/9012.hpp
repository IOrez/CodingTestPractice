#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testCase;
	string input;
	cin >> testCase;
	cin.ignore();
	while (testCase--)
	{
		getline(cin, input);
		bool check = true;
		stack<char> st;
		for (auto ch : input)
		{
			if (ch == '(')st.push(ch);
			else if (ch == ')' && !st.empty())st.pop();
			else
			{
				check = false;
				break;
			}
		}
		if (st.empty()&&check)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}