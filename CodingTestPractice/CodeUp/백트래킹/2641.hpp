#include <iostream>

using namespace std;

int DP[16][2];

int solution(int n,int cnt, bool step3=false)
{
	if (n < 0)return 0;
	else if (n == 0)return 1;
	int ret = 0;
	if (cnt == 0) { step3 = true; cnt = 2; }
	if (step3) ret += solution(n - 3, 2);
	else
		cnt--;

	ret += solution(n - 2,cnt,step3);
	ret += solution(n - 1,cnt,step3);

	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	cout << solution(n, 2, true);
	return 0;
}