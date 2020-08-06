#include <iostream>
#include <string>
#include <cstring>
using namespace std;
constexpr int Size = 'z' - 'a' + 1;
bool check[Size];
int N,Cnt;
string input;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N; cin.ignore();
	while (N--)
	{
		input = "";
		getline(cin, input);
		memset(check, false, sizeof(check));
		char preChr = ' ';
		bool isGroup = true;
		for (size_t i = 0; i < input.size()&&isGroup; ++i)
		{
			if (preChr == input[i])continue;
			if (check[input[i]-'a'])isGroup = false;
			else check[input[i] - 'a'] = true;
			preChr = input[i];
		}
		if (isGroup)Cnt++;
			
	}
	cout << Cnt;
	return 0;
}