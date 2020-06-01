#include <iostream>
#include <functional>
#include <cstring>
using namespace std;

int table[9][9];
bool check[10];

function<bool(int, int)> func[3] =
{
	[&](int r,int c)->bool
	{
		int pivotR = r / 3 * 3, pivotC = c / 3 * 3;
		memset(check,false,sizeof(check));
		for (int i = pivotR; i < pivotR + 3; ++i)
			for (int j = pivotC; j < pivotC + 3; ++j)
			{
				if (check[table[i][j]]&& table[i][j]!=0)return false;
				check[table[i][j]] = true;
			}
		return true;
	},
	[&](int r,int c)->bool
	{
		memset(check,false,sizeof(check));
		for (int j = 0; j < 9; ++j)
		{
			if (check[table[r][j]]&& table[r][j]!=0)return false;
			check[table[r][j]] = true;
		}
		return true;
	},
	[&](int r,int c)->bool
	{
		memset(check,false,sizeof(check));
		for (int j = 0; j < 9; ++j)
		{
			if (check[table[j][c]]&& table[j][c]!=0)return false;
			check[table[j][c]] = true;
		}
		return true;
	}
};

void solution(int r,int c)
{
	if (r == 9 && c == 0)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << table[i][j] << " ";
			cout << '\n';
		}
		exit(0);
	}
	else if (table[r][c] != 0) solution(r + (c + 1) / 9, (c + 1) % 9);
	else
	{
		int pivotR = r / 3 * 3, pivotC = c / 3 * 3;
		for (int i = 1; i <= 9; ++i)
		{
			bool result = true;
			table[r][c] = i;
			for (int j = 0; j < 3 && result; ++j)
				result = func[j](r, c);
			if (result)
				solution(r + (c + 1) / 9, (c + 1) % 9);
		}
		table[r][c] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> table[i][j];
	solution(0, 0);
	return 0;
}