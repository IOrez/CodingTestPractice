#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> v;
unordered_map<string, int> um;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	v.push_back(""s);
	string input;
	for (int i = 1; i <= N; ++i)
	{
		cin >> input;
		v.push_back(input);
		um.insert({ input,i });
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		if (isdigit(input[0]))
			cout << v[atoi(input.c_str())] << '\n';
		else
			cout << um[input] << '\n';
	}
	return 0;
}