#include <cstdio>

#pragma warning(disable:4996)
int ctable[50][4];


int find_max_idx(int row)
{
	int max = -1;
	int idx = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (max < ctable[row][i])
		{
			max = ctable[row][i];
			idx = i;
		}
	}
	return idx;
}

int main()
{
	
	int n, m;
	int sum = 0;
	scanf("%d %d", &n, &m);
	getchar();
	char input[51];
	char output[51];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", input);
		for (int j = 0; j < m; ++j)
		{
			switch (input[j])
			{
			case 'A':ctable[j][0]++; break;
			case 'C':ctable[j][1]++; break;
			case 'G':ctable[j][2]++; break;
			case 'T':ctable[j][3]++; break;
			}
		}
	}
	
	int index = 0;
	for (int i = 0; i < m; ++i)
	{
		int idx = find_max_idx(i);
		switch (idx)
		{
		case 0:output[index++] = 'A'; break;
		case 1:output[index++] = 'C'; break;
		case 2:output[index++] = 'G'; break;
		case 3:output[index++] = 'T'; break;
		}
		sum += n - ctable[i][idx];
	}
	output[index] = '\0';
	printf("%s\n", output);
	printf("%d\n",sum);
	return 0;
}