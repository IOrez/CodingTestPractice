/* 문제 */
/*
	피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
	
	이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

	n=17일때 까지 피보나치 수를 써보면 다음과 같다.

	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

	n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

*/

/*입력*/
/*
	첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.
*/

/*출력*/
/*
	첫째 줄에 n번째 피보나치 수를 출력한다.
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