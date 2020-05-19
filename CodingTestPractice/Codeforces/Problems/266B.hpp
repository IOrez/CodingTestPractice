#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, t;
	string input;
	cin >> n >> t;
	cin.ignore();
	getline(cin, input);
	while (t--)
	{
		int i = 0;
		while (true)
		{
			while (i + 1 < input.size() && !(input[i] == 'B' && input[i + 1] == 'G'))
				i++;

			if (i + 1 >= input.size())break;

			input[i] = input[i + 1];
			input[i + 1] = 'B';
			i +=2;
		}
	}

	cout << input;
	return 0;
}