#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	stack<char> st;
	cin >> s;
	for (auto c : s)st.push(c);
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	return 0;
}