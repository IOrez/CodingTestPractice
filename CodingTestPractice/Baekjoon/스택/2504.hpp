#include <iostream>
#include <string>
#include <stack>

using namespace std;

string input;

int solution()
{
	int result = 0;
	stack<char> cStack;
	stack<int> iStack;
	for (auto& c : input)
	{
		if (c == '(' || c == '[')cStack.push(c);
		else if (c == ')' || c == ']')
		{
			int val = 0;
			bool check = false;
			while (!cStack.empty() && !check)
			{
				char t = cStack.top();
				cStack.pop();
				if (t == '(' || t == '[')
				{
					if (t == '(' && c == ')')
						if (val == 0)val += 2;
						else val *= 2;
					else if (t == '[' && c == ']')
						if (val == 0)val += 3;
						else val *= 3;
					else return 0;
					check = true;
				}
				else
				{
					val += iStack.top();
					iStack.pop();
				}
			}
			if (!check)
				return 0;
			iStack.push(val);
			cStack.push('*');
		}
	}
	while (!cStack.empty())
	{
		char t = cStack.top();
		cStack.pop();
		if (t != '*')return 0;
		result += iStack.top();
		iStack.pop();
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	getline(cin, input);
	cout << solution();
	return 0;
}