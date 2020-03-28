#include <cstdio>
#include <string>
#pragma warning(disable:4996)

char arr[50001] = "";
char c_a[50001] = "";
char c_b[50001] = "";
int main()
{
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test) {
		int n;
		scanf("%d", &n);
		bool change = false;
		scanf("%s", arr);
		int i;
		for (i = 0; i < n; ++i)
		{
			if (arr[i] == '2')
			{
				c_a[i] = '1';
				c_b[i] = '1';
			}
			else if (arr[i] == '0') {
				c_a[i] = arr[i];
				c_b[i] = arr[i];
			}
			else if (arr[i] == '1')
			{
				if (!change)
				{
					c_a[i] = '1';
					c_b[i] = '0';
				}
				else
				{
					c_b[i] = '1';
					c_a[i] = '0';
				}
				change = !change;
			}
		}
		c_b[n] = '\0';
		c_a[n] = '\0';
		printf("%s\n", c_a);
		printf("%s\n", c_b);
	}
	return 0;
}