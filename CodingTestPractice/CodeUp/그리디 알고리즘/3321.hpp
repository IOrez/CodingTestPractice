#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int N,A,B,C;
	scanf("%d%d%d%d", &N,&A,&B,&C);

	std::vector<int> cal(N);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", &cal[i]);
	
	auto f = [&](int a, int b)->bool {return a > b; };
	sort(cal.begin(), cal.end(), f);
	float maxCalpD = (float)C/A;
	float sumCal = C;
	for (int i = 0; i < N; ++i)
	{
		sumCal += cal[i];
		int value = A + (i + 1) * B;
		float calpD = sumCal / value;
		if (maxCalpD < calpD)maxCalpD = calpD;
	}
	printf("%d", (int)maxCalpD);
	return 0;
}