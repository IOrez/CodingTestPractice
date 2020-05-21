#include <iostream>
#include <vector>
using namespace std;

vector<int> picked;
void solution(vector<int>& s,int pivot)
{
	if (picked.size() == 6)
	{
		for (auto i : picked)
			cout << i << " ";
		cout << endl;
	}
	else
	{
		for (int i = pivot; i < s.size(); ++i)
		{
			picked.push_back(s[i]);
			solution(s, i + 1);
			picked.pop_back();
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)break;
		vector<int> s(k);
		for (int i = 0; i < k; ++i)cin >> s[i];
		solution(s, 0);
		cout << endl;
	}
	return 0;
}