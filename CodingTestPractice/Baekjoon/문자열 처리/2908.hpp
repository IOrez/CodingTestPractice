#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int main()
{
	char input[2][4],output[2][4];
	int num[2];
	scanf("%s %s", input[0], input[1]);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 2; j >= 0; --j)
			output[i][j] = input[i][2 - j];
		output[i][3] = '\0';
	}

	for(int i = 0;i<3;++i)
	{ 
		if (output[0][i] > output[1][i])
		{
			cout << output[0]; break;
		}
		else if (output[0][i] < output[1][i])
		{
			cout << output[1]; break;
		}
	}

	return 0;
}