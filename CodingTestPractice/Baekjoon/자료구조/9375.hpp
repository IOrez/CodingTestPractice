#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase, N;
	string input;
	cin >> testCase;
	while (testCase--)
	{
		cin >> N; cin.ignore();
		map<string, vector<string>> m;
		for (int i = 0; i < N; ++i)
		{
			getline(cin, input);
			string wear, type;
			int idx = input.find_first_of(' ');
			wear = input.substr(0, idx - 1);
			type = input.substr(idx + 1);
			
			auto iter = m.find(type);
			if (iter != iter)
				iter->second.push_back(wear);
			else
			{
				m.insert({ type,vector<string>{}});
				m[type].push_back(wear);
			}
		}
		int sum = 1;
		for (auto& i : m)
			sum *= (i.second.size() + 1);
		cout << sum - 1 << '\n';
	}

	return 0;
}