#include <iostream>
#include <string>
using namespace std;

string picked;

char set[3] = { '1','2','3' };

void solution(int N)
{
	if (picked.size() != N)
	{
		for (int i = 0; i < 3; ++i)
		{
			picked.push_back(set[i]);
			bool check = false;
			for (int length = 1; length <= picked.size() / 2; ++length)
			{
				check = true;
				int sPivot = picked.size() - length * 2;
				int ePivot = picked.size() - length;
				for (int j = 0; j < length; ++j)
				{
					if(picked[sPivot]!=picked[ePivot])
					{
						check = false; break;
					}
					sPivot++;
					ePivot++;
				}
				if (check)break;
			}
			if (!check)solution(N);
			picked.pop_back();
		}
	}
	else
	{
		cout << picked;
		exit(0);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	solution(N);
	return 0;
}