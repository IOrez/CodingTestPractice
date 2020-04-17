#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	string word;
	getline(cin, s);
	getline(cin, word);
	queue<int> que;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == word[0])que.push(i);

	int cnt = 0;
	while (!que.empty())
	{
		int start_idx = que.front();
		que.pop();
		if (start_idx + word.size() > s.size())continue;
		bool check = true;
		for (int i = start_idx,j=0; i < start_idx + word.size(); ++i,++j)
		{
			if (s[i] != word[j])
			{
				check = false;
				break;
			}
		}
		
		if (check)
		{
			cnt++;
			int idx = start_idx;
			while (!que.empty() &&(idx = que.front()) < start_idx + word.size())
				que.pop();
		}
	}

	cout << cnt<<"\n";
	return 0;
}