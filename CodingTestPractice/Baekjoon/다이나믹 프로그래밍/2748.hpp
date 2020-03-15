/* ���� */
/*
	�Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.
	
	�̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n>=2)�� �ȴ�.

	n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.

	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

	n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/

/*�Է�*/
/*
	ù° �ٿ� n�� �־�����. n�� 90���� �۰ų� ���� �ڿ����̴�.
*/

/*���*/
/*
	ù° �ٿ� n��° �Ǻ���ġ ���� ����Ѵ�.
*/

#include <cstdio>
#pragma warning(disable:4996)

typedef struct Matrix
{
	unsigned long long c00;
	unsigned long long c01;
	unsigned long long c10;
	unsigned long long c11;
}Matrix;

Matrix fibonacchi(int n)
{
	if (n <= 0)return Matrix{ 1,0,0,0 };
	if (n <= 1)return Matrix{ 1,1,1,0 };
	Matrix m, tmp, I = { 1,1,1,0 };
	if (n % 2 == 0)
	{
		tmp = fibonacchi(n / 2);
		m.c00 = tmp.c00 * tmp.c00 + tmp.c01 * tmp.c10;
		m.c01 = tmp.c00 * tmp.c01 + tmp.c01 * tmp.c11;
		m.c10 = tmp.c10 * tmp.c00 + tmp.c11 * tmp.c10;
		m.c11 = tmp.c10 * tmp.c01 + tmp.c11 * tmp.c11;
	}
	else 
	{
		tmp = fibonacchi((n - 1) / 2);
		m.c00 = tmp.c00 * tmp.c00 + tmp.c01 * tmp.c10;
		m.c01 = tmp.c00 * tmp.c01 + tmp.c01 * tmp.c11;
		m.c10 = tmp.c10 * tmp.c00 + tmp.c11 * tmp.c10;
		m.c11 = tmp.c10 * tmp.c01 + tmp.c11 * tmp.c11;
		tmp = m;

		m.c00 = tmp.c00 * I.c00 + tmp.c01 * I.c10;
		m.c01 = tmp.c00 * I.c01 + tmp.c01 * I.c11;
		m.c10 = tmp.c10 * I.c00 + tmp.c11 * I.c10;
		m.c11 = tmp.c10 * I.c01 + tmp.c11 * I.c11;
	}
	return m;
}

int main()
{
	unsigned long long n;
	scanf("%lld", &n);
	printf("%lld", fibonacchi(n).c10);
}