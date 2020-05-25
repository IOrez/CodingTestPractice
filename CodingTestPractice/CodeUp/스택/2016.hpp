#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> st[2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, cnt = 0;
	string input;
	string output;
	cin >> N; cin.ignore();
	getline(cin, input);
	for (auto& ch : input)st[0].push(ch);
	while (!st[0].empty())
	{
		cnt++;
		st[1].push(st[0].top());
		st[0].pop();
		if (cnt % 3 == 0) { st[1].push(','); cnt = 0; }
	}
	if (cnt == 0)st[1].pop();
	while (!st[1].empty()){
		cout << st[1].top();
		st[1].pop();
	}
	return 0;
}