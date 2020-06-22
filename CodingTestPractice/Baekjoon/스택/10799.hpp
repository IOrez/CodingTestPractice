#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	bool in = false;
	stack<char> st;
	string input;
	cin >> input;
	int cnt = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '(')
		{
			in = true;
			st.push(input[i]);
		}
		else 
		{
			st.pop();
			if (in && input[i] == ')')
				cnt += st.size();
			else cnt += 1;
			in = false;
		}
	}
	cout << cnt;
	return 0;
}