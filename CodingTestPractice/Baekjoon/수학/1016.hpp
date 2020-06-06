#include <iostream>
using namespace std;

using ull = unsigned long long;

ull Min, Max, Dif, Cnt,numSize;
ull  num[1000001];
bool ch[1000001];
void solution()
{
	for (ull i = 0; i < numSize; ++i)
	{
		ull val = num[i];
		ull offset =( Min / val)* val;
		if (Min % val != 0)offset += val;
		for (ull j = offset; j <= Max; j+=val)
			if (!ch[j - Min])
			{
				ch[j - Min] = true;
				Cnt++;
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> Min >> Max;
	for (ull i = 2; i * i <= Max; ++i)
	{
		num[i - 2] = i * i;
		numSize++;
	}
	Dif = Max - Min+1;
	solution();
	cout << Dif - Cnt;
}